// Code of ShenZhou
// yellowdog.c

inherit NPC_TRAINEE;

void create()
{
        set_name("С�ƹ�", ({ "dog" }) );
        set("race", "Ұ��");
        set("age", 3);
        set("long", "һֻ���ɰ���С�ƹ���\n");
        
        set("str", 32);
        set("dex", 36);
        set("wildness", 2);

        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("chat_chance", 6);
        set("chat_msg", ({
                (: this_object(), "random_move" :),
                "С�ƹ��ñ�����������Ľš�\n",
                "С�ƹ�������ҡ��ҡβ�͡�\n" }) );
                
        set_temp("apply/attack", 10);
        set_temp("apply/armor", 3);

        setup();
}

int accept_object(object who, object ob)
{
        if( ob->id("bone") ) {
                set_leader(who);
                message("vision", name() + "���˵���������������\n", environment());
                return 1;
        }
}
