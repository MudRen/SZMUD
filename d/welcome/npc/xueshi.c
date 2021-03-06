// Code of ShenZhou
// copy from zhu.c 朱熹
// lisser

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("老学士", ({ "shi", "xue shi" }));
        set_color("$YEL$");
	set("long", "他是个精通诗理的学者。\n");
	set("gender", "男性");
	set("age", 65);
        set("max_jing", 200);
        set("max_qi", 200);
	set_skill("literate", 200);

	set_temp("apply/attack", 14);
	set_temp("apply/defense", 14);
	set_temp("apply/damage", 30);

	set("combat_exp", 400);
	set("shen_type", 1);

	set("inquiry", ([
		"学位" : "读书作官哪里比得上学武练功强？\n",
		"科举" : "读书作官哪里比得上学武练功强？\n",
	]));

	setup();
//	carry_object("/d/city/cloth")->wear();
}

int recognize_apprentice(object ob)
{	if (ob->query_skill("literate", 1) <20)
	{	ob->set_temp("mark/朱", 1);
		return 1;
	}
	else
	{	ob->delete_temp("mark/朱", 1);
		return 1;
	}
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

void greeting(object me)
{
	if (me->query_skill("literate", 1) == 0 )
	{	command("say " + RANK_D->query_respect(me) + "多读书吧，对你有好处！");
		command("say 你可以跟我学点读书(xue " + query("id") + " literate)来熟悉xue命令的使用。");
	}
	else 
	{	if (me->query_skill("literate", 1) >= 10 )
		{	command("say 快去其他地方吧，这里只是虚幻的世界。");
		}
	}
}

