// Code of ShenZhou
// huihui �ػ�

inherit NPC;

void create()
{
        set_name("�ػ�", ({ "huihui", "hui", "muslim" }));
        set("gender", "����");
        set("age", 20 + random(40));

        set("long", "һ���ϻػأ������ڵ���������Ĥ�ݡ�\n");

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

        set("chat_chance", 15);
        set("chat_msg", ({
		"�ػ�˵���º�Ĭ�����ذ�����ΰ������İ�����\n",
        }) );
}

