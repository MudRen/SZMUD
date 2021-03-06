// 版本信息: /d/jueqing/npc/jiading.c   家丁
// by jiuer 8/21/01
// 文件类型  NPC  

#include <ansi.h>
inherit NPC;

void create()
{
//	object bj;
	
	set_name("绿衣人", ({ "jiading","jia ding" }));
	set("long",
		"一个长得膀大腰圆的小伙子，一身绿衣打扮，\n"
		"说话时面露拘谨，脸上没有一丝的笑容。\n\n");
	
	set("age", 25);
	set("combat_exp", 3000);
	set("gender","男性");
	set("attitude","peaceful");
	
	add_money("coin",100);
	
	set("str", 22);
	set("dex", 20);
	set("con", 19);
	set("int", 18);
	
	set_skill("blade", 30);
	set_skill("unarmed", 30);
	set_skill("parry", 30);
	set_skill("force", 30);
	set_skill("sword", 30);
	set_skill("dodge", 30);
      
	set("jingli",200);
	set("neili",200);
	set("jing",200);
	set("qi",200);
     setup();
        carry_object("/d/jueqing/npc/obj/greenrobe")->wear();
	carry_object("/d/city/obj/changjian")->wield();
	carry_object("/d/dali/npc/obj/dagger");
}
