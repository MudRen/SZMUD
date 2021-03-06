//Modified by Lisser on k1-08
// longquan.c 龙铨
inherit NPC;

void create()
{
	set_name("龙铨", ({ "long quan", "long", "quan" }));
	set("long", "龙铨是扬威武馆的擅长刀刃的教头，为人耿直豪爽。\n");
	set("nickname", "一刀平南");
	set("title", "武馆教头");
	set("gender", "男性");
	set("age", 35);

	set_skill("literate", 50);

	set_skill("claw", 50);
	set_skill("force", 50);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("blade", 60);
        set_skill("literate", 10);
	set_skill("taixuan-gong",45);
	set_skill("liuxing-bu",55);
	set_skill("huzhua-gong",55);
	set_skill("wuhu-duanmen",55);
	map_skill("blade","wuhu-duanmen");
	map_skill("force", "taixuan-gong");
	map_skill("dodge", "liuxing-bu");
	map_skill("claw", "huzhua-gong");
	prepare_skill("claw", "huzhua-gong");

	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("combat_exp", 20000);
	set("shen_type", 1);
	setup();

	carry_object("/clone/weapon/gangdao")->wield();
}

void init()
{
        object me = this_player();

        ::init();
	if ( me->query("wuguan/pass") )
	{
		remove_call_out("get_out");
		call_out("get_out", 1, me);
	}

        if ( interactive(me=this_player()) && (int)me->query_temp("mark/马") ) {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

	command("say 欢迎这位"+RANK_D->query_respect(ob)+"，你可向我学刀法(blade)，爪法(claw)，内功(force)，招架(parry)及轻功(dodge)。");
}

int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/马"))
		return 0; 
	return 1;
}

void get_out(object me)
{
	command("hmm");
	command("say " + RANK_D->query_respect(me) + "怎么还在武馆？");
	message_vision("龙铨大手一挥，将$N赶到车房了。\n", me);
	me->move("/d/wuguan/cheku");
	return;
}
