// Filename: /d/jueqing/npc/gongsun.c
// by jiuer 01-8-21
// 文件类型  NPC  

inherit NPC;
#include <ansi.h>
string ask_me();

void create()
   {
     set_name("公孙止", ({ "gongsun zhi","gongsun", "zhi", "zhuangzhu" }));
     set("long",
		 "此人面目英俊，举止潇洒，很有轩轩高举之概，\n"
		 +"只是面皮蜡黄，容颜枯槁，不似身有绝高武功的模样。\n\n");
     set("age", 45);
	 set("combat_exp", 1000000);
     set("title","水仙庄庄主");
     set("gender","男性");
     set("attitude","peaceful");
	 set("shen_type",-1);

	 add_money("gold",1);
     
	 set("str", 28);
     set("dex", 28);
     set("con", 29);
     set("int", 25);
     
     set_skill("blade", 200);
     set_skill("parry", 200);
     set_skill("force", 200);
     set_skill("sword", 200);
     set_skill("dodge", 200);
	 set_skill("tie-zhang",200);
	 set_skill("yinyang-shuangren",200);

	 map_skill("strike","tie-zhang");
	 map_skill("blade","yinyang-shuangren");
	 map_skill("sword","yinyang-shuangren");	 
	 map_skill("parry","yinyang-shuangren");

	 prepare_skill("strike", "tie-zhang");

	 set("max_jingli",1400);
     set("jingli",1400);
     set("max_neili",1500);
     set("neili",1500);
     set("eff_jing",1500);
     set("jing",1500);
	 set("eff_qi",1500);
     set("qi",1500);
	 
	set_temp("apply/attack", 100);
	set_temp("apply/damage", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 100);

	 set("inquiry", ([
		"手令" : (: ask_me :),
		]));
	 
	 setup();
	
	 if (clonep()) carry_object("/d/jueqing/obj/blackjian");
	 carry_object("/d/jueqing/npc/obj/silkrobe")->wear();
}

int accept_kill(object me)
{
	command("say 原来你是恶贼，那就不要怪我不客气。\n");
	if (present("black jian", this_object())){
		command("wield black jian");
	}
	set_leader(me);
	kill_ob(me);
	return 1;
}

string ask_me()
{
	mapping fam; 
	object ob, me=this_object();

	if (present("shou ling", this_player()))
		return "你身上不是有手令吗？怎么又向我要？";

        ob = new("/d/jueqing/npc/obj/ling");
	ob->move(this_player());
	return "这是庄子的手令，你去找张管家，把手令交给他，他会安排妥当的。";
}
