// Code of ShenZhou
// animal: jumang.c

inherit NPC;

void create()
{
        set_name("����", ({ "ju mang", "she", "mang", "ju mang" }) );
        set("race", "����");
        set("age", 100);
        set("long", "һ����ڴ�ϸ������ͷ�����������ɶ೤��\n");
        set("attitude", "peaceful");

        set("str", 32);
        set("cor", 36);
	set("max_jing", 1000);
	set("max_qi", 2000);

        set("limbs", ({ "ͷ��", "����", "�ߴ�", "β��" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 500000);

        set_temp("apply/attack", 120);
        set_temp("apply/damage", 120);
        set_temp("apply/dodge", 100);
        set_temp("apply/armor", 100);

        setup();
}

void die()
{
        object ob;
        message_vision("$Nȫ��Ť�������ڻ��裬��춽�ֱ�����ˡ�\n", this_object());
        ob = new(__DIR__"obj/shedan");
        ob->move(environment(this_object()));
        destruct(this_object());
}
