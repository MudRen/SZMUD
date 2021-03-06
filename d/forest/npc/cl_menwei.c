//Cracked by Yujie
///d/forest/npc/cl_menwei 门卫
// by yujie 10 / 2001

inherit NPC;


void create()
{
	set_name("后堂门卫", 
              ({ "men wei", "menwei" }));
        set("title", "长乐帮");
	set("long", 
		"这是奉命在这里守卫后堂大门的门卫。\n"
		"除了香主外，谁来他都不会让进的。\n");
	set("gender", "男性");
	set("age", 25);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 23);
	set("int", 20);
	set("con", 20);
	set("dex", 23);

	set("max_qi", 300);
	set("max_jing", 200);
	set("max_neili", 100);
        set("neili", 100);
	set("combat_exp", 20000);
	set("score", 1000);

	set_skill("force", 50);
	set_skill("dodge", 40);
	set_skill("cuff", 50);
	set_skill("parry", 50);

        set("inquiry", ([
                "长乐帮" : "这里就是长乐帮总舵所在地。",
                "司徒横" : "我对我们帮主老人家的景仰之情，有如滔滔江水连绵不绝。",
                "香主" : "各位香主的任命由帮主老人家说了算。",
                "贝海石" : "贝大夫在弊帮劳苦功高，颇得帮主信任。",
                "帮主" : "我家帮主司徒大爷乃威镇江南的“东霸天”也。",
        ]));

	setup();

 	carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
	object me = this_player();
	string pos;
	
           if (stringp (me->query_temp("bangs/pos"))) 
	{	call_out("bow",1,me);
		return;
	}
		
	if ( stringp ( me->query_temp("invite")) )
		call_out("agbow",1,me);
	
	return;
		
	
}

void bow(object me)
{
	if (present(me,environment(this_object())))
		message_vision("$N对着$n行了个大礼，道：香主您老人家好！\n",this_object(),me);
	return;
}

void agbow(object me)
{
	if (present(me,environment(this_object())))
		message_vision("$N对着$n行了个大礼，道：欢迎贵宾，香主已经等候您多时了。\n",this_object(),me);
	return;
}
