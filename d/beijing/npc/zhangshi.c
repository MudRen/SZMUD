//Cracked by Roath
// seller.c

inherit NPC;
inherit F_VENDOR;

void set_vendor_status(int);

void create()
{
        set_name("����", ({ "zhang" }) );
        set("gender", "Ů��" );
        set("age", 32);
        set("long",
                "�����Ǿ��ǳ��ׯ���ϰ�����Ļ��м�����ɫ��\n");
        set("vendor_goods", ({
        }) );
        setup();
	set_vendor_status(30);
        carry_object("/d/city/obj/cloth")->wear();
        add_money("coin", 60);
}

void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

#include "/d/beijing/killme.h"
