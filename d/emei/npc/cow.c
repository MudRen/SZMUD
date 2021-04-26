// Code of ShenZhou
// /d/emei/npc/cow.c
// Shan: 96/07/09

inherit NPC;

void create()
{
        set_name("���ţ", ({ "cow", "niu", "huang niu" }) );
        set("race", "����");
        set("age", 11);
        set("long", "һͷ�ݹ���᾵Ĵ��ţ����֪��˭�ҵģ�����ͷ����س��Ųݡ�\n");

        set("str", 26);
        set("cor", 30);

        set("combat_exp", 1000);

//      set("chat_chance", 6);
//      set("chat_msg", ({
//              (: this_object(), "random_move" :),
//      }) );

        set_temp("apply/attack", 15);
        set_temp("apply/damage", 6);
        set_temp("apply/armor", 2);

        setup();
}

void die()
{
        object ob;
        message_vision("$N���ڵ��ϣ����˼��߾����ˣ�\n", this_object());
        ob = new(__DIR__"obj/beef");
        ob->move(environment(this_object()));
        ob = new(__DIR__"obj/niupi");
        ob->move(environment(this_object()));
        destruct(this_object());
}

