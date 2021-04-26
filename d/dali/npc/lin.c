// Code of ShenZhou
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("���ϰ�", ({ "lin laoban", "seller", "lin" }) );
        set("gender", "����" );
        set("age", 32);
        set("long",
 "���ϰ����������ٶ��ң�����ȥһ�ź�����\n");
        set("combat_exp", 12000);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
        set("attitude", "friendly");

	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("dodge", 30);

        set("vendor_goods", ({
	"d/shaolin/obj/fojing10.c",
	"d/shaolin/obj/fojing20.c",        
}) );
        setup();
        carry_object("/d/city/obj/cloth")->wear();
        add_money("gold", 1);
}
void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

