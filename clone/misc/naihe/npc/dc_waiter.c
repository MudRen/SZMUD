// �ĳ��������Ů��Ӧ�����ҵ������֭ѩ����ʲô��  ��/npc/dc_waiter.c
// by naihe  2002-04-29 ��ï��

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("Ů��Ӧ", ({ "waitress", "duchang waitress" }));
	set("title", "�����ĳ�");
	set("shen_type", 1);
	set("gender", "Ů��");
	set("age", 21);
	set("long","����һ�������Ů��Ӧ��ģ���崿���ˡ�\n");
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
