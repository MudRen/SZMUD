//Cracked by Roath
// quanjude_xiaoer.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("��С��", ({ "seller" }) );
        set("gender", "����" );
        set("age", 32);
        set("long",
                "����ȫ�۵µĵ�С������Կ�Ѽ�Ͻ�������ɡ�\n");
        set("combat_exp", 10000);
        set("str", 20);
        set("dex", 20);
        set("con", 20);
        set("int", 22);
        set("attitude", "friendly");
        set("vendor_goods", ({
                "/d/city/obj/kaoya",
                "/d/city/obj/jiudai",
        }) );
        setup();
        carry_object("/d/city/obj/cloth")->wear();
        add_money("silver", 10);
}

void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}
