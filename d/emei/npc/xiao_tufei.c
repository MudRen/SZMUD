// Code of ShenZhou
// xiao_tufei.c

inherit NPC;

void create()
{
        set_name("С����", ({"xiao tufei", "tufei"}));
        set("gender", "����" );
        set("age", 16+random(8));
        set("long", "���Ǹ���������С���ˣ�ɱ��Խ������޶�����\n");

        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
        set("combat_exp", 800+random(200));
		set("shen", -15);
//		set("shen_type", -1);
        set("str", 22);
        set("dex", 22);
        set("con", 20);
        set("int", 16);
        set("attitude","aggressive");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("coin", 30);
}

