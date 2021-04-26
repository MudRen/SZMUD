// zhou.c �ܲ�ͨ

#include <ansi.h>

inherit NPC;
int ask_jieyi();
int ask_jiuyin();
int ask_hubo();
int do_fangyuan();
int do_learn(string arg);
void create()
{
	set_name("�ܲ�ͨ", ({ "zhou botong", "zhou", "botong" }) );
	set("nickname",	"����ͯ");
	set("title","ȫ��̵�һ������");
	set("long", 
		"����ͷ������ֱ�����أ���ü���룬������Ͷ�������ס�ˡ�\n"
		"���뷢��Ȼ����δȫ�ף�ֻ�ǲ�֪�ж����겻�꣬����Ұ��һ��ë���׵��������ˡ�\n"
		"���ľ�ֹ���红ͯһ����\n");
	set("gender", "����" );
        set("age", 45);
	set("str",28);
	set("int",25);
	set("con",27);
	set("dex",29);
        set("combat_exp", 3600000);

        set("max_neili", 8000);
        set("neili", 8000);
        set("jiali", 0);

        set_skill("taoism", 400);
        set_skill("force", 350);
        set_skill("cuff", 350);
        set_skill("dodge", 350);
        set_skill("jinyangong", 350);
        set_skill("parry", 350);
        set_skill("kongming-quan",350);
	map_skill("force", "xiantian-gong");
	map_skill("dodge", "jinyangong");
        map_skill("cuff","kongming-quan");
        map_skill("parry","kongming-quan");
	prepare_skill("cuff","kongming-quan");

        set("inquiry", ([
		"name": "�����ܲ�ͨ�ͺ��ˡ�",
		"rumors": "�ұ��Ǹ�����а��������ʮ���꣬ÿ�����һ���������ͷ���",
		"here": "�������һ�����",
		"��а": "�ǻ�ҩʦ����޳ܵļһƭ���ҵľ�....ȥ����",
		"��ҩʦ": "����޳ܵļһƭ���ҵľ�....ȥ����",
		"����ͨ": "�ҵ�ʦ���������书��ߵģ���һ�λ�ɽ�۽�ʱ����Ϊ��һ���֡�",
		"������": "�ҵ�ʦ���������书��ߵģ���һ�λ�ɽ�۽�ʱ����Ϊ��һ���֡�",
		"�ܲ�ͨ": "������ʲô����",
		"����": "���Ż���ԧ��֯����˫��....",
		"����": "���Ż���ԧ��֯����˫��....",
		"�λ�ү": "����ͯ���¶Բ�������û���ټ����ˡ�",
		"������": "����ͯ���¶Բ�������û���ټ����ˡ�",
		"�ϵ�": "����ͯ���¶Բ�������û���ټ����ˡ�",
		"����ͯ": "�Ҿ��ǰ���������ʲô����",
		"����ȭ": "����ȭ����ʮ��·���ھ��ǣ��������ɡ���ͨ���Ρ�������Ū��ͯӹ���档",
		"kongming-quan": "����ȭ����ʮ��·���ھ��ǣ��������ɡ���ͨ���Ρ�������Ū��ͯӹ���档",
		"����": "�Ǽ�����ǰ������������Ǹ�С������",
		"����": "�����ҵĽ����ֵܣ�����Ȼɵ���ĳ����á�",
		"�һ���": "��������һ�����",
		"��": "��Ҫ������",
		"fang": "��Ҫ������",
		"Բ": "ԲҪ��Բ��",
		"yuan": "ԲҪ��Բ��",
		"�����澭": (: ask_jiuyin :),
		"˫�ֻ���": (: ask_hubo :),
		"���һ���": (: ask_hubo :),
		"hubo": (: ask_hubo :),
		"����": (: ask_jieyi :),
		"���": (: ask_jieyi :),
        ]) );
        set("double_attack", 1);
	set("rank_info/respect", "����ͯ");
	create_family("ȫ���", 1, "����");
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 15);

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object ob = this_player();

	add_action("do_fangyuan","fangyuan");
	add_action("do_draw","draw");
	add_action("do_draw","hua");
	add_action("do_learn","learn");
	add_action("do_learn","xue");
	::init();
	if (ob->query("family/family_name") == "ȫ���") {
		command("angry " + ob->query("id"));
		command("say ��ô�㵽����������ң��������Ҿ�ȥ�ʹ���˵��������ƨ�ɡ�");
	}
}

void kill_ob(object me)
{
	::kill_ob(me);
}

void unconcious()
{
	command("chat* ̾��������ͯ������Ҫ�����ˣ�������������ֻ���ܣ���Щ��ͷ���޳���һ���Ƶ�Ī�������ɫ��䡣");
	::unconcious();
}

int ask_jieyi()
{
	object ob=this_player();

	if (ob->query("zhou/jieyi")) {
		command("? " + ob->query("id"));
		command("say �������ǽ�ݹ�����");
		return 1;
	}
        if (ob->query("gender") != "����")
        {
		command("en " + ob->query("id"));
		command("say ����ƽ��ϲͬ�����˴򽻵���һ��Ů�ˣ�����̫�ࡣ�ҿ��㻹�ǳ�����գ���");
                return 1;
        }
	if (ob->query("int") > 25) {
		command("shake");
		command("say ������˹��龫������׼����ʲô�����ء�");
		return 1;
	}
	if ((int)ob->query("shen") <= -1000) {
		command("shake");
		command("say ����Ȼ������㣬��ʦ��̻岻����������а֮������Ҫ����ġ�");
		return 1;
	}
	command("nod " + ob->query("id"));
	if (ob->query("gender") == "����") {
		command("say �ðɣ����Ҿͽ��Ϊ�ֵܰɡ�");
	}
	message_vision("�ܲ�ͨ��$N�����������˵����������ͯ�ܲ�ͨ��������" + ob->name() +"���������պ��и��������ѹ���������Υ�����ģ������书ȫʧ����С��СèҲ�򲻹�����\n", ob);
	ob->set("zhou/jieyi", 1);
	return 1;
}

int ask_jiuyin()
{
	object ob=this_player();

	if (ob->query_temp("get_jiuyin") == 2) {
		command("? " + ob->query("id"));
		command("say �����Ѿ���������");
		return 1;
	}
	if (ob->query("zhou/jieyi")) {
		if (query_temp("jiuyin_send")) {
 			command("say �����������ˣ��ǡ������澭�����Ѿ���ȥ�����ˡ�");
			return 1;
		}
		command("say �ǡ������澭�����Ͼ��ģ��������������е�ʯϻ֮�ڣ����ø����㣬����....");
		ob->set_temp("get_jiuyin", 1);
		return 1;
	}
	command("say ����������ʲô����");
	return 1;
}

int ask_hubo()
{
	object ob=this_player();
	int hubo;

	if (ob->query("double_attack")) {
		command("? " + ob->query("id"));
		command("say �㲻���Ѿ�ѧ������");
		return 1;
	}
	hubo = ob->query_temp("zuoyou_hubo");
	if (hubo == 22) {
		command("say ��������һ�Σ�");
		return 1;
	}
	if (hubo == 1) {
		command("say ��������Ϳ����");
		return 1;
	}
	if (hubo > 1 && hubo <= 21) {
		command("say ��ô����������ɣ����������Ů����������͸��һ���Ķ�������ʮ�߰˸��ϣ��������Ź�������ʼ��ѧ���ᣡ");
		return 1;
	}
	if (ob->query_skill("force") < 100 || ob->query("max_neili") < 500 || ob->query("combat_exp") < 10000) {
		command("say �㻹���ȴ����ѧ������˵�ɡ�");
		return 1;
	}
	command("say ���Ź��������ڶ�������֮ʱ��������������˵�����ѵ�������˵����Ҳ����֮�����е���һѧ��ᣬ�е���һ����Ҳѧ���ˣ�Խ�Ǵ�����Խ�ǲ��ɡ�");
	command("say �����������һ�Σ����ֻ���(fang)�����ֻ�Բ(yuan)��");
	ob->set_temp("zuoyou_hubo", 1);
	return 1;
}

int do_fangyuan()
{
	object ob=this_player();
	int hubo;

	if (ob->is_busy() || ob->is_fighting())	return notify_fail("����æ���أ�\n");
	hubo = ob->query_temp("zuoyou_hubo");
	if (!hubo) return 0;
	if (hubo < 21) {
		message_vision("$N�������ʳָ�ڵ��ϻ��������������ķ����е���ԲȦ��ԲȦ���е��󷽿顣\n", ob);
		ob->add_temp("zuoyou_hubo", 1);
		return 1;
	}
	if (hubo == 21) {
		message_vision("$N�������ʳָ�ڵ��ϻ��������������ķ����е���ԲȦ��ԲȦ���е��󷽿顣\n", ob);
		command("haha " + ob->query("id"));
		command("say ��ô������һ�±�첻����");
		ob->add_temp("zuoyou_hubo", 1);
		return 1;
	}
	if (hubo == 22) {
        if (ob->query("kar") > 24 && ob->query("int") < 16 )
             {
			say("�ܲ�ͨ���һ�������˰��βŵ������ⶨ�������̥��ѧ���ı��죬�Ǳ��װ��ˡ���\n");
			message_vision("�ܲ�ͨ����������������������ޱȵ��湦��һ���Զ����̸���$N��\n", ob);
			ob->delete_temp("zuoyou_hubo");
			ob->set("double_attack", 1);
			if (ob->query_skill("force") < 100 || ob->query("max_neili") < 500)
				message_vision("��ϧ$N��Ϊ�ڹ���Ϊ���ޣ����ڻ���û����⡣\n", ob);
			else
//			ob->set("double_attack", 1);
			return 1;
		}
		message_vision("$N���������ʳָ�ڵ��ϻ����������������Ծ��Ƿ����е���ԲȦ��ԲȦ���е��󷽿顣\n", ob);
		message_vision("$N���ڷ����Լ���һ����Ҳ���������Ź����ˡ�\n", ob);
		ob->delete_temp("zuoyou_hubo");
		command("disapp " + ob->query("id"));
		return 1;
	}
	return 0;
}

int do_draw(string arg)
{
	object ob=this_player();

	if (!ob->query_temp("zuoyou_hubo")) return 0;
	if (arg == "fang" || arg == "��" || arg == "yuan" || arg == "Բ") return notify_fail("�ܲ�ͨŭ��������ͬʱ����Բ��\n");
	if (arg == "fang yuan" || arg == "��Բ") return do_fangyuan();
	return 0;
}
/*
int accept_object(object who, object ob)
{
	if (ob->id("jiuyin xiajuan") && ob->query("material") == "leather") 
	{
		if (who->query_temp("get_jiuyin") == 1) {
			tell_object(who, "�ܲ�ͨ��Ȼ�뵽��һ����Ƥ���ӣ�˵���������Ҽ�Ȼ���壬�ҾͰ����ڶ�����ʮ�������������һЩ����Ҳ�̸���ɡ���\n");
			new_ob("../obj/jiuyin1.c")->move(who);
			tell_object(who, "�ܲ�ͨ����һ���������澭���Ͼ�\n");
			tell_object(who, "�ܲ�ͨ�ѡ������澭���¾������㡣\n");
			command("hehe " + who->query("id"));
			who->set_temp("get_jiuyin", 2);
			set_temp("jiuyin_send", 1);
			return notify_fail("");
		}
		else {
			command("? " + who->query("id"));
			command("say ���������ʲô��\n");
			return notify_fail("");
		}
	}
	return 0;
}
*/
int do_learn(string arg)
{
	object me=this_player();
	string skill, teacher, skill_name;
	object ob;
	int master_skill, my_skill, gin_cost, rand;

        if (me->is_busy())
                return 0;

	if(!arg || (sscanf(arg, "%s %s", teacher, skill)!=2 ))
		return 0;

	if (teacher != "zhou" && teacher != "botong")
		return 0;

	if( me->is_fighting() )
		return 0;

	if( !(ob = present(teacher, environment(me))) || !ob->is_character()) {
		write("��Ҫ��˭��̣�\n");
		return 1;
	}

	if( !living(ob) ) {
		write("��....����Ȱ�" + ob->name() + "Ū����˵��\n");
		return 1;
	}

	if( !me->query("zhou/jieyi")) {
		write("�ܲ�ͨ��ֵؿ����㣬�ʵ�������˭ѽ��\n");
		return	1;
	}

	if (skill != "kongming-quan" && skill != "����ȭ") {
		write("���������±����ұ���ѧ�ˡ�\n");
		return 1;
	}

	my_skill = me->query_skill(skill, 1);
	master_skill = ob->query_skill(skill, 1);
	if( my_skill >= master_skill ) {
		write("���ڿ���ȭ�ϵ������Ѿ���������ͯ�ˣ�\n");
		return 1;
	}

	if( !SKILL_D(skill)->valid_learn(me) ) {
		write("������ǿ��ֲ������㹻���ڹ��������ſ���ѧϰ����ȭ��\n");
		return 1;
	}

	gin_cost = 150 / (int)me->query("int");

	if( !my_skill ) {
		gin_cost *= 2;
		me->set_skill(skill,0);
	}

	rand = random(20);
	if (rand == 4)
		gin_cost *= 2;
	else if (rand == 15)
		gin_cost += 4;

	if( (int)me->query("learned_points") >= (int)me->query("potential") ){
		write("���Ǳ���Ѿ����ӵ������ˣ�û�а취��ѧ�ˡ�\n");
		return 1;
	}

	message_vision("$N��$n����йء�����ȭ�������⡣\n", me, ob);

	if( (int)me->query("jing") > gin_cost ) {
        write("�ܲ�ͨ��������ӡ����¾������о仰��������ֲ��Ϊ���������ޣ�����֮�á��仧���Ϊ�ң������ޣ�����֮�á���\n");
		write("�ܲ�ͨ���ھ����������ȱ�����ò��ף���ӯ���壬���ò��\n");
		if( (string)SKILL_D(skill)->type()=="martial"
		&&	my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) {
			write("Ҳ����ȱ��ʵս���飬�������ͯ�Ľ��������޷���ᡣ\n");
		} 
		else {
			if (rand == 13) {
				write("��������ͼ�������е����ʱ������ͯ��Ȼ�����Աߴ����������ֹ�����˸�ƨ�����ң�������ķ����ҡ�\n");
				write("�����ʲô��ûѧ����\n");
				return 1;
			}
			else if (rand == 5) {
				write("�ܲ�ͨ���������䣬��Ȼ���ͷ�������������������������ĸ��˴�ܿɺã���\n");
				write("�����ֻ��������ˣ��һ��\n");
				return 1;
			}
			else if (rand == 4) {
				write("��������ͼ�������е����ʱ������ͯ��Ȼ�����Աߴ����������ֹ�����˸�ƨ�����ң�������ķ����ҡ�\n");
				write("����㻨�˱�ƽ����һ���ľ�����\n");
			}
			else if (rand == 15) {
				write("��������ͼ�������е����ʱ������ͯ��Ȼ�����Աߴ����������ֹ�����˸�ƨ�����ң�������ķ����ҡ�\n");
				write("����㻨�˱�ƽ����ö�ľ�����\n");
			}
			if(skill_name = SKILL_D(skill)->query_skill_name(my_skill))
				write("����������ͯ��ָ�����ԡ�" + skill_name + "����һ���ƺ���Щ�ĵá�\n");
			else
				write("����������ͯ��ָ�����ƺ���Щ�ĵá�\n");
			me->add("learned_points", 1);
			me->improve_skill(skill, random(me->query_int()));
		}
	} 
	else {
		gin_cost = me->query("jing");
		write("�����̫���ˣ����ʲôҲû��ѧ����\n");
	}

	me->receive_damage("jing", gin_cost );

	return 1;
}
