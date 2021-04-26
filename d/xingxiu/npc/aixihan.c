// Code of ShenZhou
// seller.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("������", ({ "aixihan", "seller", "girl" }) );
	set("gender", "Ů��" );
	set("title", "��ñ̯��");
	set("age", 20);
	set("long", "һλ����ñ�Ļ�����Ů��\n�������ǻ���Ů��������õ����֣����纺�˵ķҷ�����֮�ࡣ\n");
	set("shen_type", 1);
	set("combat_exp", 1000);
	set("str", 22);
	set("dex", 20);
	set("con", 20);
	set("int", 20);
	set("attitude", "peaceful");
	set("vendor_goods", ({
		"/d/xingxiu/obj/huamao2",
		"/d/xingxiu/obj/huamao1",
		"/d/xingxiu/obj/huamao3",
	}) );

	setup();
	add_money("coin", 100);
}

void init()
{	
	object ob;

	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");

	if( interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	string msg;
	if( !ob || environment(ob) != environment() ) return;
	if(ob->query("gender") == "Ů��") {
		if(ob->query("age") < 20) msg = "ɭ�ܶ�";
		else if(ob->query("age") < 30) msg = "��ǡ";
		else msg = "���Ῠ";
	}
	else {
		if(ob->query("age") < 20) msg = "����";
		else msg = "����";
	}
	say ("������΢΢����˵�������ã�"+msg+"��\n");
	return;
}
