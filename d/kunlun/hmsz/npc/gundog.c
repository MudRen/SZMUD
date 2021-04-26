// gundog.c (kunlun)

inherit NPC;

void create()
{
	set_name("��Ȯ", ({ "gun dog", "dog" }) );
	set("race", "Ұ��");
	set("age", 4);
	set("long", "һֻ����ͦ�أ���߳���¶�Ű�ɭɭ�ĳ�������̬�׺ݵ���Ȯ.\n");
	set("attitude", "peaceful");
	
	set("str", 26);
	set("cor", 30);

	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 10000);
	set("chat_msg_combat", ({
		(: this_object(), "random_move" :),
		"ֻ�����������������ͣ���ͷ��߳�������Ȯ�ѽ�������Χס��\n",
		"����ȮԶԶ���������Ϣ��������צ�ķ�����һʱ�������˽�������\n"
	}) );
		
	set_temp("apply/attack", 25);
	set_temp("apply/damage", 1);
	set_temp("apply/armor", 30);

	setup();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) &&
		random(ob->query_kar() + ob->query_per()) < 30) {
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
	}	
}
