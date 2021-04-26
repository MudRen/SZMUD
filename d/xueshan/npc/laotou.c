// Code of ShenZhou
// Summer, 10/16/96. 

inherit NPC;

string ask_me_1();
string ask_me_2();
string ask_me_3();
string ask_me_4();
string* homes = ({
        "/d/city/guangchang",
        "/d/quanzhou/zhongxin",
        "/d/wudang/shanmen",
        "/d/shaolin/fzlou",
        "/d/shaolin/guangchang1",
        "/d/taishan/fengchan",
        "/d/taishan/huima",
        "/d/huashan/laojun",
        "/d/village/square",
        "/d/xingxiu/tianroad3",
        "/d/forest/bank3",
        "/d/emei/baoguomen",
        "/d/emei/xixiang",
        "/d/qilian/qilian",
	"/d/xixia/square",
});

void create()
{
	set_name("��ͷ��", ({"laotou zi", "laotou"}));
	set("long",
		"���˼������֣�ͷ���Ǿ���û�еģ�һ���ȱ��ҷʵ��Դ��ᰲ��˫��֮�ϣ�\n"
		"���Ƴ����µ�֮ʱ���������ص�ͷһ颣�������Դ����£���ձǿ�ȫ����\n"
		"�ᳶ�˿�ȥһ�㡣\n"
	);


	set("gender", "����");
	set("attitude", "friendly");

	set("age", 50);
	set("shen_type", 0);
	set("str", 26);
	set("int", 23);
	set("con", 24);
	set("dex", 26);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("combat_exp", 50000);
	set("score", 100);

	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);

	set("apply/attack", 160);
        set("apply/defense", 160);
	set("apply/damage", 50);

	set("chat_chance", 15);
        set("chat_msg", ({
//                "��ͷ�����������������Ƶꣿһ���������ҩҲû�С������ϰ�Ҳ��֪�㵽����ȥ�ˡ�\n",	
		(: random_move :),
//		"��ͷ�Ӷ���˵������λ�͹ٿ��м�������ĵ��ϰ壿�����ȣ���Ů�����Ŀ첻���ˣ����뵽������ҵ��ҩ��\n",
//		"��ͷ��ͻȻ�ŵ���������������һ�ԣ��͹���������ҩ���������Ұɣ������ɶҲû�С�\n",
	"��ͷ�Ӳ�������ؽ����������Ǯ����һ��Ц�������������ڨ��\n",
	"��ͷ�ӽ��������Լ���Ǯ������·���Է��������ζ��ֵ�Ц����������\n",
	}) );
	set("inquiry", ([
		"ǧ������" :    (: ask_me_1 :),
		"��ɽ��" :    (: ask_me_2 :),
		"��֥" :   (: ask_me_3 :),
		"��ҩ" : "����֪��ɶ�������Ұɣ����µ�ҩ�Ҷ���������ʲ��ǧ�����ڡ���֥����ɽ�Ρ����ȵȡ�\n",
		"�����˵�" :  (: ask_me_4 :),
	]));

	set("stay_chance", 1);

        set("no_clean_up", 1);
	set("wu_count", 5);
	set("shan_count",  5);
	set("ling_count", 3);
	set("dan_count", 1);
	setup();
	carry_object("/clone/misc/cloth")->wear();
}
void init()
{
        ::init();
        set_heart_beat(1);
}
string ask_me_1()
{
	object ob;

//	if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
//		return "�Բ����ⶫ��������Ů���ù��ˡ�";

	if (  present("heshou wu", this_player()) )
		return "�Ҳ��Ǹ�����������";

	if (query("wu_count") < 1) return "�Բ����ⶫ��������Ů���ù��ˡ�";

	say("��ͷ��̾��һ�������ȣ�ǧ���������Ů���������ˣ�Ҳ����ʲ����ɫ...\n");
	this_player()->set_temp("marks/��", 1);
	return "������ֻ��һ֧�������εģ���Ů��Ҳ�ò����ˡ�ֻҪһ���ƽ𣬱��������㡣\n";
}
string ask_me_2()
{
	object ob;

	if (  present("lao shanshen", this_player()) )
	return "�Ҳ��Ǹ�����������";
		
	if (query("shan_count") < 1) return "�Բ����ⶫ����Ů�����ù��ˡ�";
	this_player()->set_temp("marks/ɽ", 1);
	say("��ͷ���૵�����Ů���ѳ����������ⶫ����ֻ������Խ��Խ��������\n");
	return "�ⶫ���ҵ��У�����Ҫ�Ҿ������㣬һ���ƽ𣬲����͹�ǧ����ԣ��Զ��˲��á�\n";
}
string ask_me_3()
{
	object ob;
	
	if (  present("ling zhi", this_player()) )
		return  "�Ҳ��Ǹ�����������";

	if (query("ling_count") < 1) return  "��֥������ҩ�����Ѳɵ�����������û�С�";
	this_player()->set_temp("marks/��", 1);
	say("��ͷ��̧��ͷ�������������´�����һ�������ٺٺ١���Ц�˼���...\n");
	return "��֥���Ǻܹ��ص�ࡣ�����������Ҫ�����ƽ𣬲����ۡ�\n";
}
string ask_me_4()
{
        object ob, me = this_player();
        if (  present("xuming badan", this_player()) )
        return "�Ҳ��Ǹ�����������";

        if (me->query_condition("xx_poison") < 50
	&& me->query_condition("snake_poison") < 50 
	&& me->query_condition("sl_poison") < 50
	&& me->query_condition("insect_poison") < 50)
	 return "��λ" + RANK_D->query_respect(this_player())+
	"�����������к��ز���Ҫ��ҩ������\n";

	if (query("dan_count") < 1)
	return "�Բ�������������û�С�";
        say("�Ҷ������ɼ�ǧ���˲Ρ����ߡ���֥�����顢¹�ס����ڡ��ܵ������ߡ������������ҩ�ģ�������ɹ, �Ƴɰ˿����������������˵�������\n");
	ob = new("/d/qilian/obj/badan");
	ob->move(me);
	message_vision("��ͷ�Ӵӻ�����ͳ�һ�������˵��ݸ�$N��\n",me);
	add("dan_count", -1);
	add("stay_chance", -1);
        return "�õ����������þ�����������ͷ���ң���������˵�����ȥ���ðɣ���ʹ��������������Ҳ�����㼸�������ɡ�\n";
}
int accept_object(object me, object ob)
{
	object where = environment();
	 object *chars = ({});
	object wu, shan, ling;
	if (!clonep()) return 1;

        ::chat();

        if (add("tick", 1)%3 == 1) return 1;

	if(ob->query("money_id") && ob->value() >= 20000
        && me->query_temp("marks/��") ) {
        ling = new("/d/qilian/obj/lingzhi");
        ling->move(this_player());
	add("ling_count", -1);
        me->delete_temp("marks/��");
        message_vision("��ͷ�Ӵ�Ƥ�Ҵ�����ͳ�һö��֥�ݸ�$N��\n",me);
	add("stay_chance", -1);
	if ((int)query("tick") > 600 ) {
                set("tick", 0);
                return_home(where);
        }

        if (sizeof(chars)<1 && me->query("stay_chance")<1)
        {
                set("stay_chance", 1+random(3));
                random_move();
        }

        return 1;
        }

	if(ob->query("money_id") && ob->value() >= 10000
        && me->query_temp("marks/��") ) {
	switch( random(3) )
        {
            case 0:
        wu = new("/d/qilian/obj/shouwu");
	break;
	case 1:
	wu = new("/d/qilian/obj/shouwu");
	break;
	case 2:
	wu = new("/d/qilian/obj/fakewu");
	break;
	}
        wu->move(me);
        add("wu_count", -1);
	add("stay_chance", -1);
	me->delete_temp("marks/��");
	message_vision("��ͷ�Ӵ�Ƥ�Ҵ�����ͳ�һ�ú����ڵݸ�$N��\n",me);
	return 1;
	}
	
        if(ob->query("money_id") && ob->value() >= 10000
        && me->query_temp("marks/ɽ") ){
	switch( random(3) )
        {
            case 0:
	shan = new("/d/qilian/obj/fakeshen");
        break;
        case 1:
	shan = new("/d/qilian/obj/shanshen");
        break;
        case 2:
	shan = new("/d/qilian/obj/shanshen");
        break;
        }
        shan = new("/d/qilian/obj/shanshen");
        shan->move(me);
        add("shan_count", -1);
	add("stay_chance", -1);
        me->delete_temp("marks/ɽ");
        message_vision("��ͷ�Ӵ�Ƥ�Ҵ�����ͳ�һ����ɽ�εݸ�$N��\n",me);
        return 1;
        }  
	say(
	"��ͷ��һ�漱æ�Ѷ�����������һ��Ц����˵����" + RANK_D->query_respect(ob) + "��������ҩ������˵��С��û��Ū�����ġ�\n");
	return 1;
}
void destroy (object ob)
{
        destruct(ob);
        return;
}
int return_home(object home)
{
                // Are we at home already?
        if( !environment()
	||      environment()==home )
                return 1;

        // Are we able to leave?
        if( !living(this_object())
        ||      is_fighting() ) return 0;

        // Leave for home now.
        message("vision", this_object()->name() + "����ææ���뿪�ˡ�\n",
                environment(), this_object());

        home = load_object(homes[random(sizeof(homes))]);
        if (home) return move(home);
        return 0;
}
