// squirrel 松鼠
// /d/jueqing/npc/squirrel.c
// Date: 08/2001

inherit NPC;

void create()
{
        set_name("松鼠", ({ "song shu","squirrel","shu"}) );
        set("race", "野兽");
        set("age", 2);
        set("long", "一只跳来跳去的小松鼠。\n");
        set("attitude", "peaceful");
        set_weight(300);

        set("combat_exp", 10);

        set("chat_chance",8);
		set("chat_msg", ({
			(: this_object(), "random_move" :),
			"小松鼠一下跳到你跟前，立起身子盯着你。\n",
			"小松鼠抱着果子'咔嚓咔嚓'地咬了几口。\n",
			"小松鼠被你一惊，'噗'地一下爬上了树！\n",
			}) );
		
		set_temp("apply/attack", 5);
		set_temp("apply/dodge",20);
		set_temp("apply/armor", 1);	
		
		setup();
}
