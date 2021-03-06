// Code of ShenZhou
//xiaofan.c 小贩

inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;

void create()
{
        set_name("小老板", ({ "lao ban", "seller"}));
	set("title", "杂货铺老板");
	set("shen_type", 1);

	set("gender", "男性");
	set("age", 45);
	set("long",
                "也不知道是哪里来的混到长安城来，做了几年的小买卖。\n");
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
