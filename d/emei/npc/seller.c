// Code of ShenZhou
// /d/emei/npc/seller.c С��
// Shan: 96/07/09

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("С��", ({ "xiao fan", "seller", "fan" }) );
	set("gender", "����" );
	set("age", 32);
	set("long",
"���Ǹ�С������������������ʵʵ����ɱ�������Ƕ��ֱ��ˡ�\n");
	set("shen_type", 1);
	set("combat_exp", 300);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
	set("attitude", "peaceful");
	set("vendor_goods", ({
		"/d/emei/obj/map",
		"/d/village/npc/obj/stick",
		"/d/village/npc/obj/shoes",
                "/d/village/npc/obj/bottle",
		"/d/city/obj/peanut",
		"/d/xingxiu/obj/fire",
		"/d/huashan/obj/rope",
		"/clone/weapon/tieqiao",
	}) );
	setup();
        carry_object("clone/misc/cloth")->wear();
	add_money("coin", 100);
}
void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

