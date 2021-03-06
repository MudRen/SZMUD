// /d/newjob/builder/npc/shijiang.c
// for new business systme   老石翁

inherit NPC;
string ask_job();

void create()
{
	set_name("老石翁", ({"lao shiweng", "weng" }));
	set("long",
		"一位满脸沧桑的老人。但他两眼炯炯有神，一把雪白胡须飘至胸口。\n"
		"左手拿了一把开山凿，右手拿了一把大锤子。\n"
		);

	set("gender", "男性");
	set("attitude", "friendly");
	set("age", 60);
	set("shen_type", 1);

    set("str", 20);
    set("int", 20);
    set("con", 20);
    set("dex", 20);

    set("max_qi", 1000);
    set("max_jing", 1000);
    set("jiali", 40);
  
    set("apply/attack", 125);
    set("apply/defense", 125);
    set("combat_exp", 50000);
    set("score", 100);
  
    set("chat_chance", 10);
    set("chat_msg", ({ "老石翁嘟哝道：凿石眼要瞄正，下锤手要稳。\n", }) );
    set("inquiry", ([
		"job" : (: ask_job :),
		"开山凿" : "开山凿是采石头的重要工具。\n",
		"chisel" : "开山凿是采石头的重要工具。\n",
		"大锤" : "大锤是采石头的重要工具。\n",
		"hammer" : "大锤是采石头的重要工具。\n",
		"炸药" : "客官要能出好价钱，我倒是可以到我老哥子那儿问一问。\n",
		"explosive" : "客官要能出好价钱，我倒是可以到我老哥子那儿问一问。\n",
		]));

	setup();
	
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/newjob/builder/obj/chisel")->wield();
}

string ask_job()
{
	mapping job_stat;
    object ob1, ob2;
    object hammer, chisel;
    object ob = this_player();
    object me = this_object();

    int good_skill;

    job_stat = ob->query_temp("sj/job");

    if( ob->is_busy() )
	{
		command( "hmm "+ob->query( "id") );
		return "你还在忙着干别的事呢！\n";
	}

	if ( job_stat )
	{
		command( "hmm "+ob->query( "id" ) );
		return "你还没完成任务，就又想要新的？\n";
	}

	command("nod");
	command("say 好，你去给我采些石头来吧。");
	chisel = present( "chisel", ob );
	if ( chisel )
		destruct( chisel );
	hammer = present( "hammer", ob );
	if ( hammer )
		destruct( hammer );

	ob1 = new( "chisel" );
    ob1->move( ob );
    ob2 = new( "hammer" );
    ob2->move( ob );

    ob->set_temp( "sj/job", 1 );
	return "早去早回，路上要小心一些！\n";
}

int accept_object(object me, object obj)
{
	object ob = this_player();
    object hammer, chisel;
    if ( obj->query( "id" ) == "Yan Shi" )
	{
		if ( ob->query_temp( "sj/job", 1 ) )
		{
			ob->delete_temp("qz/caiyao");
			ob->add( "combat_exp", ( 50 + random( 30 ) ) );
			chisel = present( "chisel", ob );
			if ( chisel )
				destruct( chisel );
			hammer = present( "hammer", ob );
			if ( hammer )
				destruct( hammer );
			return 1;
		}
	}
	return 0;
}

void destroy (object ob)
{
	destruct(ob);
	return;
}