// NPC:   /d/jueqing/npc/tongzi.c
// 制作人: jiuer 08/2001

#include <ansi.h>
inherit NPC;
int ask_zhuangzhu();
void greeting(object);

void create()
{
	object ob;
	set_name("僮子", ({ "tong zi", "tongzi", "tong" }));
	set("long","他是一个十来岁的小侍僮，正笑眯眯地看着你。\n");
	
	set("gender","男性");
	set("age", 10);
	set("attitude","friendly");

	set("str", 20);
	set("dex", 28);
	set("con", 28);
	set("int", 28);
	
	set_skill("literate", 28);
	set_skill("unarmed", 10);
	set_skill("parry", 10);
	set_skill("force", 10);
	set_skill("sword", 10);
	set_skill("dodge", 10);
	
	set("jingli",100);
	set("max_neili",100);
	set("neili",100);
	set("eff_jing",100);
	set("eff_qi",200);
	set("combat_exp", 100);
	set("shen_type",1);
	
	set("inquiry", ([
			"庄主"   : 	(: ask_zhuangzhu :), 
		]));
	
	setup();

	carry_object("/d/quanzhou/obj/fuchen")->wield();
	carry_object("/d/jueqing/npc/obj/greenrobe")->wear();
}

void init()
{
	object me = this_player();
	
	::init();

	if( interactive(me) )
	{
		remove_call_out("greeting");
        call_out("greeting", 1, me);
	}
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment())
		return;
	switch(random(2)) 
	{
	case 0 :
		say("小僮子笑着迎过来道：「敝处荒僻得紧，从无外人到访，\n"
			+"今日贵客降临，幸何如之。却不知这位" + RANK_D->query_respect(ob) + "有何贵干？」\n");
		break;
	case 1 :
		say("小僮子笑着说道：「你来是拜见我家庄主的吗？嘻嘻」\n");
		break;
	}
}

int ask_zhuangzhu()
{
	object me = this_player(),here;
	string desc;
    here = environment(me);	
	desc = here->query("long");
	
	if ( (int)here->query_temp("opened") == 0)
	{
		say("僮子笑道：「原来是远道来见庄主的，请进吧。」\n");
		say("僮子一边说一边把大石门打开。\n");
		here->set("exits/enter", "/d/jueqing/changlang1"); 
	}
	else
	{
		say("僮子微一躬身说道：「庄主正在室中，你进去找他吧。」\n");
	}
	return 1;
}


