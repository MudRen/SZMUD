// Code of ShenZhou
// seller.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("�ٶ����", ({ "zaier ger", "ger", "man" }) );
        set("gender", "����" );
        set("title","���չ���");
        set("age", 30);
        set("long", "����һλ���������Ϲ������������ഫ���ַ��������Ρ���ʯ���ߡ�\n"
        "���ٶ��������ά������˼������������ʯ���յĹ�����\n");
        set("shen_type", 1);
        set("combat_exp", 8000);
        set("str", 18);
        set("dex", 20);
        set("con", 16);
        set("int", 20);
        set("attitude", "peaceful");
        set("vendor_goods", ({
		"/d/xingxiu/obj/yeguang",
		"/d/xingxiu/obj/necklace",
		"/d/xingxiu/obj/earring",
        }) );
        setup();
        add_money("silver", 5);
	carry_object("/clone/armor/wcloth")->wear();

}
void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}
