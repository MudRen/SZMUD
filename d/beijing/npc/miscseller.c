//Cracked by Roath
// seller.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("С��", ({ "seller" }) );
        set("gender", "����" );
        set("age", 32);
        set("long",
                "���Ǹ�С����������������ʵʵ�������������Ƕ��ͱ��ˡ�\n");
        set("combat_exp", 300);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
  	set("chat_chance", 10);
	set("chat_msg", ({
	"С�����������͹٣���ݾ��ǵĵ�ͼ�ɣ������������������\n",
	"С�����������͹٣��򶥲�ñ�ɣ������ﶬ�����ð���\n",
        "С��������������⾩�ǿɴ�����û�е�ͼ����Ƕ����Ҳ��š�\n",
        "С��������������������죬û׼��Ҫ��������û��ñ���а���\n",
	}));
        set("attitude", "friendly");
        set("vendor_goods", ({
                "/d/beijing/obj/map",
                "/d/beijing/obj/caomao",
        }) );
        setup();
        carry_object("/d/city/obj/cloth")->wear();
        add_money("coin", 60);
}

void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}
