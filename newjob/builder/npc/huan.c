//by jiuer
// huan.c 獾

inherit NPC;

void create()
{
	set_name("獾", ({ "huan", "badger" }) );
	set("race", "野兽");
	set("age", 5);
	set("long", "一只毛灰色，善掘土，穴居山野，昼伏夜出的小獾。
听说它的毛可制笔，毛皮可制裘，其脂肪熬炼的獾
油可治疗烫伤。大家又给它一个俗名「狗獾」。\n");
	set("attitude", "peaceful");
	
//	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
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
	message_vision("$N凄惨的嚎了几声，死了。\n", this_object());
	ob1 = new("/newjob/builder/obj/huanrou");
	ob2 = new("/newjob/builder/obj/huanpi");
	ob1->move(environment(this_object()));
	ob2->move(environment(this_object()));
	destruct(this_object());
}
