// Code of ShenZhou
// zhangzi.c ���

inherit NPC;

void create()
{
	set_name("���", ({ "zhang zi", "zhang", "deer" }) );
	set("race", "Ұ��");
	set("age", 5);
	set("long", "һƥС��ӣ�������С¹��ͷ��û�нǡ�\n");
	set("attitude", "peaceful");
	
        set("str", 20);
        set("dex", 30);

//	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
//	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 150);

//	set("chat_chance", 6);
//	set("chat_msg", ({
//		(: this_object(), "random_move" :),
//	}) );
	
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 5);
	set_temp("apply/armor", 2);

	setup();
}

void die()
{
	object ob;
	message_vision("$N��ҵĺ��˼��������ڵ������ˡ�\n", this_object());
	ob = new("d/gaibang/obj/zhangrou");
	ob->move(environment(this_object()));
	destruct(this_object());
}
	
