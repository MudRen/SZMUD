// Code of ShenZhou
// deer.c ÷��¹

inherit NPC;

void create()
{
	set_name("÷��¹", ({ "meihua lu", "lu", "deer" }) );
        set("race", "Ұ��");
	set("age", 5);
	set("long","һֻ��˳��÷��¹������ԲԲ�����������㣬�Ե�ʮ�ֺ��档\n");
	set("attitude", "peaceful");
	
//	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
//	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 500);
//	set("shen_type", 0);

//	set("chat_chance", 6);
//	set("chat_msg", ({
//		(: this_object(), "random_move" :),
//	}) );
	
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 12);
	set_temp("apply/armor", 11);

	setup();
}

void die()
{
	object ob;
	message_vision("$N��ҵĺ��˼��������ˡ�\n", this_object());
	ob = new(__DIR__"lurou");
	ob->move(environment(this_object()));
	destruct(this_object());
}
	
