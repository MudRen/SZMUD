// Code of ShenZhou
inherit NPC;

void create()
{
        set_name("���", ({ "pei cong" }));
        set("gender", "����");
        set("age", 20 + random(40));

        set("long", "һ������ͷ�����ӡ�\n");

        set("attitude", "friendly");

        set("combat_exp", 4000);
        set("shen_type", 1);

        set_skill("unarmed", 20);
        set_skill("parry", 20);
        set_skill("dodge", 20);

        set_temp("apply/attack", 15);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 20);

        setup();

        set("chat_chance", 2);
        set("chat_msg", ({
                "��ӣ��������ǳ�ȥ���Խ��ơ�\n",
        }) );
}

