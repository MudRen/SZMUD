// Code of ShenZhou
// shopkeeper.c 

inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;

void create()
{
        set_name("���ϰ�", ({ "chen laoban", "lao ban", "chen", "laoban" }));
        set("shen_type", 1);

        set("gender", "����");
        set("age", 45);
        set("long",
                "����ƽ�����ӻ��̵��ϰ壬����������ʮ�����������\n");
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_temp("apply/damage", 15);

        set("combat_exp", 40000);
        set("attitude", "friendly");
        set("vendor_goods", ({
                "/d/heimuya/obj/fengguan",
                "/d/heimuya/obj/magua",
                "/d/heimuya/obj/xiapi",
                "/d/heimuya/obj/chaoxue",
                "/d/heimuya/obj/flower-shoe",
                "/d/heimuya/obj/pnecklace",
                "/d/xingxiu/npc/obj/fire",
        }));
        
        setup();
}

void init()
{
        ::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
