// injured_monkey.c

inherit NPC;

void create()
{
	set_name("小猴",({ "injured monkey", "monkey"}) );
	set("gender", "雄性");
	set("race", "野兽");
	set("age", 2);
	set("long", "这是一只急奔逃命的猴子,后股上带了一枝短箭,显然被人用箭射伤.\n"
	    "它股上中箭之后，不能窜高上树，这时筋疲力竭，再也爬不起来。\n");
	set("shen", 0);
	set("str", 20);
	set("dex", 20);
	set("con", 20);
	set("int", 20);
        set("attitude", "peaceful");

	set("max_qi", 400);
	set("qi", 400);
	set("max_jing", 200);
	set("jing", 200);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 0);
	set("combat_exp", 10000);

	set_skill("force", 35); 
	set_skill("strike", 35);
	set_skill("dodge", 35);
	set_skill("parry", 35);
	set("fight_times", 0);	

	set("chat_chance", 15);
	set("chat_msg", ({
		"猴儿目光中露出乞怜和恐惧的神色。\n",
	}));
	setup();       
}
