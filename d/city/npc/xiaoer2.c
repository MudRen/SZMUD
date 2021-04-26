// Code of ShenZhou
// xiaoer2.c �Ƶ�С��

inherit NPC;
inherit F_DEALER;

string ask_me(string);

void create()
{
	set_name("��С��", ({ "xiao er", "xiao", "waiter" }) );
	set("gender", "����" );
	set("age", 22);
	set("long",
		"��λ��С����Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "С����");
	set("vendor_goods", ({
		__DIR__"obj/jitui",
		__DIR__"obj/jiudai",
		__DIR__"obj/baozi",
	}));
        set("inquiry", ([
            "����" : (: ask_me, "oil" :),
            "Ѽ��" : (: ask_me, "duck" :),
        ]) );

	setup();
}

void init()
{	
	object ob; 
	mapping myfam; 

	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() ) {
		if ( (myfam = ob->query("family")) 
		&& myfam["family_name"] == "ؤ��" 
		&& ob->query_skill("begging",1) > 10 )
		{
			remove_call_out("saying");
			call_out("saying", 0, ob);
		}
		else
		{ 
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		}
	}

	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "��С��Ц�����˵������λ" + RANK_D->query_respect(ob)
				+ "�������ȱ��裬ЪЪ�Ȱɡ�\n");
			break;
		case 1:
			say( "��С���ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
				+ "����������\n");
			break;
	}
}

void saying(object ob)
{
        if (!ob || environment(ob) != environment()) return;

	say("\n��С�����һ���������Ҫ���Ľ�����ʲ�᣿ ���ҹ���ȥ��\n\n");
	remove_call_out("kicking");
	call_out("kicking", 1, ob);
	
}

void kicking(object ob)
{
        if (!ob || environment(ob) != environment()) return;

	ob->move("/d/city/beidajie2");
	message("vision","ֻ����ƹ����һ����" +  ob->query("name") +
		"���˴�����¥��һ�����˳������Ǳ���״���ӿ��ˡ�\n", environment(ob), ob);
}
int accept_kill(object obj)
{
//      ������ô�flood���ʸĶ���   Sure
        command("say ��λ�͹پ������� " + obj->name() + "���" 
	+ RANK_D->query_rude(obj) + "Ҫɱ���ң�");
}

string ask_me(string name)
{
	object me = this_player();

	if ( name == "oil" ) {
		me->set_temp("ask_oil", 1);
		return "���������͸�С�ļ������ӣ�����ȥ������Щ�����ϡ�";
	}

	if ( name == "duck" )
		return "Ѽ�ƣ�����¥��Щ��Ѽ����Ѽ�����������͵��ˣ�";
}

int accept_object(object who, object ob)
{
        if ( ob->query("money_id") ) {
		if ( ob->value() >= 700 && who->query_temp("ask_oil") ) {
			tell_object(who, "��С��һ������˵������л���ϣ�С����͸�����Щ��������\n");
			remove_call_out("get_oil");
			call_out("get_oil", 2, this_object(), who);
			return 1;
		}

		tell_object(who, "��С��һ������˵������л���ϣ�\n");
		return 1;
	}

	return 0;
}		

void get_oil(object ob, object me)
{
        object ob1 = new("clone/food/jiyou");

	message_vision("$n������ת��һȦ���ø�$Nһ�޶�����\n", me, ob);
	ob1->move(me);
	me->delete_temp("ask_oil");
}

