// Code of ShenZhou
// xiao_louluo.c

inherit NPC;

void create()
{
        set_name("С���", ({"xiao louluo", "louluo"}) );
        set("gender", "����" );
        set("age", 14+random(8));
        set("long", "����һ����Ͳ����С��ޣ����ǵ�һ�γ��������ޱ����⡣\n");

        set_temp("apply/attack", 5);
        set_temp("apply/defense", 5);
        set("combat_exp", 50);
//		set("shen_type", -1);
        set("shen", -15);
        set("str", 10+random(10));
        set("dex", 20);
        set("con", 18);
        set("int", 15);
        set("attitude","aggressive");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("coin", 10);
}
