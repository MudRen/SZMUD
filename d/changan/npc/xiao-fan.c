// Code of ShenZhou
//xiaofan.c С��

inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;

void create()
{
        set_name("С�ϰ�", ({ "lao ban", "seller"}));
	set("title", "�ӻ����ϰ�");
	set("shen_type", 1);

	set("gender", "����");
	set("age", 45);
	set("long",
                "Ҳ��֪�����������Ļ쵽�������������˼����С������\n");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 40000);
	set("attitude", "friendly");
	set("vendor_goods", ({
		"/d/city/obj/fandai",
                "/d/city/obj/beixin",
                "/d/city/obj/douli",
                "/d/city/obj/doupeng",
                "/d/city/obj/heyeli",
		"/d/xingxiu/npc/obj/fire",
		"/clone/money/pocket",
	}));
	
	setup();
}

void init()
{
	::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
