// 版本信息:  /d/jueqing/npc/crocodile     鳄鱼
// 制作人:    jiuer 8/22/01
// 文件类型   NPC  

inherit NPC;
#include <ansi.h>

void create()
   {
	set_name("鳄鱼", ({ "crocodile","e yu","eyu" }));
	set("race", "野兽");
	set("age", 35);
	set("long","一只体大无比，身上长着暴鳞的大鳄鱼。它正悄悄向你游过来，随时准备袭击你。\n");
	set("weight", 300000);
	set("combat_exp", 20000);
	
//	set("attitude","aggressive");
	
//	set("wildness", 12);
	set("str", 40);
	set("dex", 40);
	set("int", 40);
	
	set_temp("apply/attack", 50);
	set_temp("apply/damage", 70);
	set_temp("apply/armor",  30);
	
	set("chat_chance", 10);
	set("chat_msg_combat", ({
		(: this_object(), "random_move" :),
		"\n鳄鱼暗暗地浮在水面上，突然一起身，张开大嘴向你横咬过来！\n",
		"\n鳄鱼尾巴一甩，忽然一个大扭身，反扑了下来！\n",
	}) );
	
	setup();
}

void die()
{
	message_vision("\n$N被一脚击中要害，四肢抽搐了几下，大嘴一张歪倒下了。\n", this_object());
	::die();
}
