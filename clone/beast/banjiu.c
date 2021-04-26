// Code of ShenZhou
// banjiu.c ���

inherit NPC;

void create()
{
	set_name("���", ({ "ban jiu", "bird"}) );
	set("race", "Ұ��");
	set("age", 2);
	set("long", "һֻ��С��娛\n");
	set("attitude", "peaceful");
	
        set("limbs", ({ "ͷ��", "����", "���", "צ��", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 100);

	set_temp("apply/attack", 2);
	set_temp("apply/defense", 6);
	set_temp("apply/damage", 1);
	set_temp("apply/armor", 1);

	setup();
}

void die()
{
	object ob = new(__DIR__"obj/banjiu-rou");

	message_vision("$N�����ϵ����������ˡ�\n", this_object());
	ob->move(environment(this_object()));
	destruct(this_object());
}

