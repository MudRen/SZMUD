// Code of ShenZhou
inherit NPC;

void create()
{
        set_name("����", ({ "you ren", "ren" }) );
        set("gender", "����" );
        set("age", 22+random(30));
        set("int", 28);
        set("long",
                "���������������ͨ���ա�\n");

        set("attitude", "peaceful");
        set("combat_exp", 400+random(2200));
        set_skill("literate", 40);
        setup();
}

