// Code of ShenZhou
// yang.c ���ϰ� 

inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;

void create()
{
	set_name("������", ({ "yang yongfu", "yang" }));
	set("title", "�ӻ����ϰ�");
	set("shen_type", 1);

	set("gender", "����");
	set("age", 45);
	set("long",
		"���ϰ������������������ˣ����˼�ʮ���С������\n");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 40000);
	set("attitude", "friendly");
	set("vendor_goods", ({
                "/clone/misc/npctu",
		"/d/city/obj/fandai",
		__DIR__"obj/beixin",
		__DIR__"obj/douli",
		__DIR__"obj/doupeng",
		__DIR__"obj/heyeli",
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
