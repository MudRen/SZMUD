//by jiuer
// huan.c �

inherit NPC;

void create()
{
	set_name("�", ({ "huan", "badger" }) );
	set("race", "Ұ��");
	set("age", 5);
	set("long", "һֻë��ɫ���ƾ�����Ѩ��ɽҰ�����ҹ����Сⵡ�
��˵����ë���Ʊʣ�ëƤ�����ã���֬���������
�Ϳ��������ˡ�����ָ���һ����������ⵡ���\n");
	set("attitude", "peaceful");
	
//	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
//	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 50);
//	set("shen_type", 0);

//	set("chat_chance", 6);
//	set("chat_msg", ({
//		(: this_object(), "random_move" :),
//	}) );
	
	set_temp("apply/attack", 5);
	set_temp("apply/defense", 5);
	set_temp("apply/damage", 4);
	set_temp("apply/armor", 1);

	setup();
}

void die()         // not open now
{
	object ob1, ob2;
	message_vision("$N��ҵĺ��˼��������ˡ�\n", this_object());
	ob1 = new("/newjob/builder/obj/huanrou");
	ob2 = new("/newjob/builder/obj/huanpi");
	ob1->move(environment(this_object()));
	ob2->move(environment(this_object()));
	destruct(this_object());
}
