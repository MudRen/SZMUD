// Code of ShenZhou
// shenu.c ��ū
// maco

/***************************************************************

breed		: ���ڿ�ѧpoison�ļ���
new_breed	: ����һ���������߳ɹ��ᣬ��ѧpoison�ļ���
new_breed_time	: ����һ�ο�ʼ�������ߵ�ʱ��
checked_snake	: �Ƿ������εĹ��ߣ�

***************************************************************/
#include <ansi.h>

inherit NPC;

int ask_snake();
int ask_guaishe();
int do_order(string);

void create()
{
	set_name("��ū", ({ "she nu" ,"nu"}));
	set("long", "���Ǹ��𿴹ܰ���ɽׯ�߳�����ū��������ׯ���������������ߵ�����\n");
	set("gender", "����");
	set("title", "����ɽׯ");
	set("age", 35);

	set_skill("hand", 30);
	set_skill("shexing-diaoshou", 30);
	set_skill("dodge", 20);
	set_skill("parry", 30);
	set_skill("force", 20);
	map_skill("hand","shexing-diaoshou");
	map_skill("dodge","chanchubu");
	prepare_skill("hand","shexing-diaoshou");

	set("str", 28);
	set("int", 21);
	set("con", 27);
	set("dex", 21);

	set("max_neili", 200);
	set("jiali", 10);
	set("combat_exp", 10000);

	set("attitude", "peaceful");
	set("shen_type", -1);
	set("inquiry", ([
		"��" : (: ask_snake :),
		"snake" : (: ask_snake :),		
		"����" : (: ask_guaishe :),
		"guaishe" : (: ask_guaishe :),
	]));

	setup();
	carry_object("/d/xingxiu/obj/wcloth")->wear();
}

void init()
{
	::init();
	add_action("do_order", "order");
}

int ask_snake()
{
	object me, snake;
	int time, poison, breed, new_breed;

	me = this_player();

	poison = (int)me->query_skill("poison",1);
	breed = me->query("baituo/breed");
	new_breed = me->query("baituo/new_breed");

	if( me->query("family/family_name") != "����ɽ" ) {
		command("say "+RANK_D->query_rude(me)+"��������ǵ��߶���Ī�Ƕ���ʲ�����Խ");
		return 1;
	}

	if (me->query("family/master_name") != "ŷ����") {
		command("say ��������߶���ׯ���������������ġ�");
		return 1;
	}

	if( !me->query("baituo/new_breed_time") && !me->query("baituo/checked_snake")) {
		command("say ������û�����������ߣ�����Ҳ����Щ�᣿");
		return 1;
	}

	if( me->query("baituo/checked_snake") ) {
		command("say �����ϴ��������������н�����Ƿ�Ҫ��׽�µ�Ʒ����������");
		return 1;
	}

	time = time() - me->query("baituo/new_breed_time");

	if(time < 600) {
		command("say ����ǰ��׽��������Ⱥ��С������ҹҹ�����Ŀ��ˣ��͵����Ƿ�ֳ�ˡ�");
		return 1;
	}

	if(time < 1200) {
		command("say ����ǰ��׽���������Ѿ��µ��ˣ���ؽ��ձ�������");
		return 1;
	}

	command("say С���Ѿ������ˣ�С�����ȥ����������");
	message_vision("\n��ū�Ҵ�ææ��������ȥ��\n", me);
	
	this_object()->move("/d/baituo/temproom");

        remove_call_out("bring_snake");
        call_out("bring_snake", 3, me);
        return 1;
}

void bring_snake(object me)
{
	object snake;
	int poison, breed, new_breed;
	string result;

	poison = (int)me->query_skill("poison",1);
	breed = me->query("baituo/breed");
	new_breed = me->query("baituo/new_breed");

	if( new_breed > poison+10 )  new_breed = poison + 10; 
	if( new_breed > 400 ) new_breed = 400;

	this_object()->move("/d/baituo/shechang");

	snake = new("/d/baituo/npc/new_snake");

	if( new_breed > poison ) {
		snake->set_name("С����", ({ "guai she", "she", "snake" }) );
		snake->set_color("$HIW$");
		snake->set("long", 
		"һ������������С�ߣ���״���죬�ǰ���ɽ����"+me->name()+"��"
		+chinese_number(me->query("baituo/manage"))+"�������������֡�\n"
		);
		if( breed >= 400 )
		result = HIW"�������ߵĶ����Ͷ�һ���������ɼ�����߶������գ���Ȼ�������⡣\n"NOR;
		else if( new_breed > breed ) 
		result = HIY"��ɹ����������˶��Ը�ʤԭ�ֵĹ��ߣ�\n"NOR
		+ "���������ն���ķ��������࣬������������������������"+chinese_number(new_breed)+"����\n";
		else result = "��Ȼ���������˹��ߣ�������̬������ǰ��Ʒ����������ض�������������\n";
	}
	else if( new_breed >= 240 ) {
		snake->set_name("С����", ({ "guai she", "she", "snake" }) );
		snake->set_color("$HIW$");
		snake->set("long", 
		"һ������������С�ߣ���״���죬�ǰ���ɽ����"+me->name()+"��"
		+chinese_number(me->query("baituo/manage"))+"�������������֡�\n"
		);
		result = "��Ȼ���������˹��ߣ����������ʹ��������ԣ���ȶ��ԵĹ��߳Ʋ���ͻ�ƣ��������������������ѡ�\n";
	}
	else {
		snake->set_name("С����", ({ "snake", "she"}) );
		snake->set("long", 
		"һ�����Ǽ�ͷ��С�ߣ��ǰ���ɽ����"+me->name()+"��"
		+chinese_number(me->query("baituo/manage"))+"�������������֡�\n"
		);
		if( !breed || breed == 0 )
		result = "�������߲�������֮��������������������ֲ����ɹ���\n";
		else if( new_breed > breed ) 
		result = "����ϸ���ӣ����������ߵĶ�����Ȼʤ���ϻ�������Ʒ�֣�Ȼ�����ɲ������롣\n";
		else result = "����ϸ���꣬ȴ���������ߺ�������֮�����������Է����ȴ�ǰ���ˡ�\n";
	}

	message_vision("\n����һ�������ū���˳�����\n", me);
	command("say �������������С���ж�����ǿ��һ������������Ŀ��");
	message_vision("һ��"+snake->name()+"���ѵ����˹�����\n", me);

	snake->move(environment(me));
	snake->set_leader(me);
	snake->set("who_breed", me->query("id"));
	snake->set("snake_poison", new_breed);

	write(result);

	log_file("test/breed_snake",
		sprintf("%s(%s) ��%d�����������%s(����%d) on %s \n", 
		me->name(), me->query("id"), me->query("baituo/manage"), snake->name(), new_breed, ctime(time())));

	if(new_breed > breed) {
		me->set("baituo/breed", new_breed);
		me->add("baituo/success_breed", 1);
		if( me->query_skill("training") < 400 )
			me->improve_skill("training", new_breed*10 );
		if( me->query_skill("poison") < 400 )
			me->improve_skill("poison", new_breed*10 );
	}
	me->set("baituo/checked_snake", 1);
	me->delete("baituo/new_breed");
	me->delete("baituo/new_breed_time");

	return;
}

int ask_guaishe()
{
	object me;
	int num;
	me = this_player();
	num = me->query("baituo/snake_amount");

	if( me->query("family/family_name") != "����ɽ" ) {
		command("say "+RANK_D->query_rude(me)+"��������ǰ���ɽ�Ĺ��ߣ�Ī�Ƕ���ʲ�����Խ");
		return 1;
	}

	if( me->query("family/master_name") != "ŷ����" ) {
		command("say ׯ���������Ѿ���˼���������֮���໥�ӽ����Ų�����Щ����֮���Ĺ��ߡ�");
		return 1;
	}
	if ( num < 1)
		command("say ���³�����û���������Ĺ��ߡ�");
	else command("say �������ڳ�����Ĺ��ߣ�һ����"+chinese_number(num)+"����");

	if ( num > 10 )
	command("admire "+me->query("id"));
	return 1;
}

int do_order(string arg)
{
	object me, room;
	int flag;
	me = this_player();
	
	if( me->query("family/family_name") != "����ɽ" ) return 0;

	room = load_object("/d/baituo/shegu1");

	if( room->query("defense") ) flag = 1;
	
	if ( arg == "defense") {

		if( flag ) return notify_fail("�߹�����Ѿ��ɶ�����ס�ˡ�\n");

		if( me->query("family/master_name") != "ŷ����" ) {
			message_vision(CYN"$N����ū����ų��ܽ��е��߶�����ס�߹ȵ���ڣ�\n"NOR, me);
			command("bored "+me->query("id"));
			command("say �ߣ�Ҫ��Ҫ��ȣ����Ҷ�����������");
			return 1;
		}

		message_vision(CYN"$N����ū����ų��ܽ��е��߶�����ס�߹ȵ���ڣ�\n"NOR, me);
		message_vision("��ū���������ش�Ӧ���˵��߳�һ�ǣ��������ͷ��ܽѶ����Ļ��ء�\n", me);
		message_vision(HIR"\n�������߳��⴫��һ��˻˻���졭��\n"NOR, me);
		
		message("vision", HIR"��ͻȻ����һ��˻˻���죬һƬѪ��ɫ��������������������������������������ȿڡ���\n\n"NOR,room );
		room->set("defense", 1);
		command("say �����������ˣ�");
	}

	else if( arg == "remove" ) {
		if( !flag ) return notify_fail("�߹�������ڱ���û�ж�����\n");


		if( me->query("family/master_name") != "ŷ����" ) {
			message_vision(CYN"$N����ū���ֹͣ���ܽ��ͷŶ����������߹ȵ���ڣ�\n"NOR, me);
			command("kick "+me->query("id"));
			command("say ���뺦���Ҳ��ɣ�û��ׯ�����˭���ÿ��߹ȣ�");
			return 1;
		}
		message_vision(CYN"$N����ū���ֹͣ���ܽ��ͷŶ����������߹ȵ���ڣ�\n"NOR, me);
		message_vision(CYN"$N�ٺ���Ц��˵����"+RANK_D->query_self_rude(me)+"Ҫ����Щ�Ծ��������ɵ�������Ϲ����������߶�������\n"NOR, me);

		command("fear "+me->query("id"));
		message_vision("��ū������ɫ�����Ǳ�$Nб��һ�ɣ�����սս�������˿�������˻��ء�\n", me);
		message_vision(WHT"\n�������߳��⴫��һ��˻˻���죬���źܿ��ְ���������\n"NOR, me);
		message("vision", WHT"��ͻȻ����һ��˻˻���죬�������߹�ǰ�ĺ���������ɢ������Ҳû��������ð������\n��һ�����������ɢ���߹ȵ������ȫ��������ǰ��\n\n"NOR,room );
		room->delete("defense");

		command("say ������С�������Ը������˶�������ׯ��Ҫ�����������ɵõ���ס����");
	}

	else return notify_fail("��Ҫ����ū��ʲ����� (defense or remove) \n");

	return 1;
}
