// Code of ShenZhou
// /d/emei/npc/bat.c ����
// Shan 6/24/96

inherit NPC;

void create()
{
        set_name("����", ({ "bianfu", "bat" }) );
        set("race", "Ұ��");
        set("age", 3);
        set("long", "�ڰ�����Լ����һֻ��ɫ������\n");
        set("attitude", "peaceful");

        set("limbs", ({ "ͷ��", "����", "���", "צ��", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 300);
        set_temp("apply/attack", 3);
        set_temp("apply/defense", 5);
        set_temp("apply/armor", 1);

        setup();

        set("chat_chance", 2);
        set("chat_msg", ({
                "һֻ���������߷ɹ���\n",
                "һֻ�����Ȼͣ�����ͷ��\n",
                "��һֻ����ͣ������ߵ���ʯ�ϡ�\n",
                "�ڰ���һֻ����ͣ�����ұߵ���ʯ�ϡ�\n",
                "�ڰ���һֻ����ͣ����ǰ�����ʯ�ϡ�\n",
                "������һֻ����ͣ����������ʯ�ϡ�\n",
        }) );
}

int is_grpfight()
{
        object me=this_object();
        object ob;
        int i;

        message_vision("��Χ��"+me->name()+"һ����$n���˹�������\n\n", me, this_player());
        for (i=0;i<sizeof(all_inventory(environment(me)));i++)
                if (objectp(ob=present("bianfu "+(i+1), environment(me))))
                        ob->kill_ob(this_player());
        return 1;
}

