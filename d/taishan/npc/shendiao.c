// Code of ShenZhou
// ���
// qfy July 10, 1996

inherit NPC;

void create()
{
        set_name("���", ({ "shen diao", "diao" }) );
        set("race", "����");
	set("subrace","����");
        set("age", 60);
        set("long", 
"һͷ��ª֮���Ĵ��ȫ����ë�������䣬���Ǳ��˰�ȥ��һ�����\n"
"�ģ�ëɫ�ƺڣ��Ե����ǰ��ࡣ������������ͷ��������Ѫ��Ĵ�\n"
"������˫����֣��������̣���֪��η��裬ֻ�Ǹ�������������һ\n"
"���������š�\n");
        set("attitude", "peaceful");

        set("limbs", ({ "ͷ��", "����", "���", "צ��", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("max_jing", 1000);
        set("max_qi",   1000);
        set("max_neili",1000);
        set("neili",    1000);
        set("jiali",     100);

        set("combat_exp", 100000);
        set_temp("apply/attack", 90);
        set_temp("apply/damage", 90);
        set_temp("apply/dodge",  90);
        set_temp("apply/armor",  90);

	set_skill("dodge", 120);
	set_skill("claw", 120);

        set("chat_chance", 10);
        set("chat_msg", ({
		"�������������ص������㡣\n",
		"����ɡ��Ľ���һ����\n",
                "����������ڶ�ǰ������ȥ��\n",
		"�����ɽ��ǰ��������ͷ��������������ͷ�����㡣\n",
        }) );

	setup();
}
