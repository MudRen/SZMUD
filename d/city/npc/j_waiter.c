// Code of ShenZhou
// j_waiter.c

inherit NPC;
inherit F_VENDOR;
void greeting(object ob);

void create()
{
	set_name("�ƹ�С��", ({ "xiao er", "xiao", "waiter", "jiuguan waiter" }) );
	set("gender", "����" );
	set("age", 22);
	set("long",
		"��λ�ƹ�С����Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "С����");
	set("vendor_goods", ({
                __DIR__"obj/peanut",
                __DIR__"obj/tofu",
        }));
        set("inquiry", ([
        "���" : "�ٺ٣�����С���Կ䣬������ľƿ�ȫ���ϵȵĺþƣ�\n",
        "��" : "�͹�Ҫ�Ⱦƿ��������Եط��ˣ���¥�������롣\n",
	]));
	
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
			remove_call_out("greeting");
		}
		else
		{ 
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		}
	}

	add_action("do_buy", "buy");
//	add_action("do_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;

	switch( random(2) ) {
		case 0:
			say( "�ƹ�С��Ц�����˵������λ" + RANK_D->query_respect(ob)
				+ "�������ȵ��ůů���Ӱɡ�\n");
			break;
		case 1:
			say( "�ƹ�С���ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
				+ "������������������Ŀɶ��Ǻþư���\n");
			break;
	}
}
