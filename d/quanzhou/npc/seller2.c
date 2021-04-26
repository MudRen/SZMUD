// Code of ShenZhou
// /d/quanzhou/npc/seller2.c ̯��
// Shan: 96/07/09

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("̯��", ({ "tan fan", "seller", "fan" }) );
	set("gender", "����" );
	set("age", 28);
	set("long",
"���Ǹ������ܸɵ�С̯������Ū��̯����ĸ���������ҩƷ������������������ߺ���š�\n");
	set("shen_type", 1);
	set("combat_exp", 60000);
        set("str", 26);
        set("dex", 25);
        set("con", 22);
        set("int", 23);
	set("attitude", "peaceful");
	set("vendor_goods", ({
		"/d/quanzhou/npc/obj/renshen-guo",
		"/clone/weapon/changjian",
		"/clone/weapon/wandao",
		"/clone/weapon/hammer",
		"/clone/weapon/stick",
		"/clone/weapon/zhubang",
		"/d/city/obj/jinchuang",
                "/d/village/npc/obj/bottle",
		"/clone/food/jiudai",
		"/clone/food/kaoya",
	}) );
	setup();
        carry_object("clone/misc/cloth")->wear();
}

void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

