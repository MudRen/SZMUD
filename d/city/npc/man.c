// Code of ShenZhou
// poorman.c

inherit NPC;

void create()
{
        set_name("׳��", ({ "man", "han" }) );
        set("gender", "����" );
        set("age", 33+random(10));
        set("long", "һ����ʵ��׳����\n");
        set("attitude", "peaceful");
        set("combat_exp", 1500);
//	set("shen", 50);
	set("shen_type", 1);
        set("str", 20);
        set("dex", 18);
        set("con", 17);
        set("int", 13);
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
	add_money("coin", random(10));
}

