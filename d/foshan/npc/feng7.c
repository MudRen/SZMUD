// Code of ShenZhou

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("����", ({ "feng qi", "feng" }));
	set("title", "��¥�ϰ�");
	set("shen_type", -1);

	set("gender", "����");
	set("age", 45);
	set("long",
		"�����Ƿ����ϵ�Զ����ܣ�����Ӣ��¥���ƹ��书û��ʲô��Ϊ��ȴ���ǻ��顣\n");

	set("combat_exp", 200);
	set("attitude", "friendly");
	
	set("vendor_goods", ({
		"/d/city/obj/kaoya",
		"/d/city/obj/tofu",
		"/d/city/obj/peanut",
		"/d/city/obj/jiudai",
	}));

	setup();
}

void init()
{
	object ob;
	
	::init();
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment())
		return;
	say("����Ц���е�˵������λ" + RANK_D->query_respect(ob) +
		"�����������\n");
}
