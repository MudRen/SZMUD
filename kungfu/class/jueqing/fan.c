// /d/jueqing/npc/fan.c
// Jiuer 2001-8-28  

inherit NPC;

void create()
{
	set_name("樊一翁", ({ "fan yiweng","fan" }));
	set("long",
"这老者身材极矮，不逾四尺，五岳朝天，相貌清奇，最奇的是
一丛胡子直垂至地，身穿墨绿色布袍，腰束绿色草绳，形貌极是古怪。\n\n");
	
         set("age", 50);
	 set("combat_exp", 200000);
	 set("bellicosity", 1);
	 
	 set("gender","男性");
	 set("attitude","aggressive");
	 
	 add_money("silver",10);
     
	 set("str", 28);
	 set("dex", 25);
     set("con", 23);
     set("int", 19);
     
	 set_skill("staff", 120);
     set_skill("unarmed", 120);
     set_skill("parry", 120);
     set_skill("force", 120);
     set_skill("dodge", 120);
	 
	 set("max_jingli",1000);
	 set("jingli",1000);
	 set("max_neili",1000);
	 set("neili",1000);
	 set("eff_jing",1000);
	 
	 set("jing",1000);
	 set("eff_qi",1000);
	 set("qi",1000);

	 setup();

         carry_object("/d/jueqing/npc/obj/staff")->wield();
         carry_object("/d/jueqing/npc/obj/greenrobe")->wear();
}


