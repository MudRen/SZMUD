// Code of ShenZhou
// punk.c

inherit NPC;

int ask_me();

void create()
{
        set_name("С��å", ({"punk"}) );
        set("gender", "����" );
        set("age", 18);
        set("long", "����һ�����ֺ��е�С��å��\n");

        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
        set("combat_exp", 500);
//	set("shen", -100);
	set("shen_type", -1);
        set("str", 25);
        set("dex", 20);
        set("con", 18);
        set("int", 15);
        set("attitude","heroism");
        setup();

        carry_object(__DIR__"obj/cloth")->wear();
	add_money("coin", random(100));
}
