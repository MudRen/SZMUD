// gundog.c (kunlun)

inherit NPC;

void create()
{
	set_name("猎犬", ({ "gun dog", "dog" }) );
	set("race", "野兽");
	set("age", 4);
	set("long", "一只昂首挺胸，身高齿利露着白森森的长牙，神态凶狠的猎犬.\n");
	set("attitude", "peaceful");
	
	set("str", 26);
	set("cor", 30);

	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 10000);
	set("chat_msg_combat", ({
		(: this_object(), "random_move" :),
		"只听得汪汪汪几声急吠，几头身高齿利的猎犬已将你团团围住。\n",
		"众猎犬远远嗅着你的气息，张牙舞爪的发威，一时还不敢扑将上来。\n"
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
