// Code of ShenZhou
// taolao.c ������

inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;

void create()
{
	set_name("������", ({ "tao lao", "tao", "lao" }));
	set("title", "��Ȼ����ϰ�");
	set("shen_type", 1);

	set("str", 30);
	set("gender", "����");
	set("age", 55);
	set("long",
		"�������ǳ������Ϻ��ˣ������Ĳ������ֺã���Ǯ������\n"
		"���Գ�����˶�ϲ����������衣\n");
	set("combat_exp", 1000);
	set("attitude", "friendly");
	
	set("vendor_goods", ({
		__DIR__"obj/wulong",
		__DIR__"obj/guanying",
		__DIR__"obj/longjing",
		__DIR__"obj/moli",
		__DIR__"obj/xiangpian",
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
	switch(random(2)) {
	case 0 :
		say("������Ц���е�˵������λ" + RANK_D->query_respect(ob) +
			"����������ȱ��Ȳ衣\n");
		break;
	case 1 :
		say("������˵����Ӵ����λ" + RANK_D->query_respect(ob) + 
			"��������˵���һ�����ʲ�Ҷ���������ɡ�\n");
		break;
	}
}
