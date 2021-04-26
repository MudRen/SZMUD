// 赌场茶座里的女侍应，卖我的曲奇果汁雪茄烟什么的  ★/npc/dc_waiter.c
// by naihe  2002-04-29 于茂名

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("女侍应", ({ "waitress", "duchang waitress" }));
	set("title", "泊来赌场");
	set("shen_type", 1);
	set("gender", "女性");
	set("age", 21);
	set("long","这是一个年轻的女侍应，模样清纯可人。\n");
	set("combat_exp", 1000);
	set("attitude", "friendly");
	set("vendor_goods", ({
                __DIR__"obj/cooky",
                __DIR__"obj/cake",
                __DIR__"obj/coffee",
                __DIR__"obj/ajuice",
                __DIR__"obj/ojuice",
                __DIR__"obj/segar",
                __DIR__"obj/smsegar",
        }));
        
        setup();
}

void init()
{
        ::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
