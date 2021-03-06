//ROOM damen.c

inherit ROOM;

void create()
{
	set("short", "独尊厅大门");
        set("long",@LONG
这就是通向『灵鹫宫』独尊厅的大门。大门左右各有一头石雕的猛鹫
，高达三丈有余，尖喙巨爪，神骏非凡，栩栩如生，似乎随时要腾空而去。
LONG
	);
        set("outdoors", "lingjiu");
        set("exits", ([
		"north" : __DIR__"dating",
		"south" : __DIR__"dadao2",
        ]));

	set("objects",([
		CLASS_D("lingjiu") + "/meijian" : 1,
		CLASS_D("lingjiu") + "/lanjian" : 1,
	]));
	set("cost", 1);
	setup();
}

int valid_leave(object me, string dir)
{
	if ( me->query("job_status")==1) 	
	return notify_fail
                ("你现在身负守卫要任，不能擅离职守！\n");

	if (  (dir == "north")
           && ((string)me->query("family/family_name") != "灵鹫宫")
	   && ( objectp(present("meijian", environment(me)))
	   ||   objectp(present("lanjian", environment(me))) ) )

	 return notify_fail
		("梅兰双姝伸手拦住你，说道：“非灵鹫宫弟子请回！”\n");
	return ::valid_leave(me, dir);
}
void init()
{
        add_action("do_kill","kill");
        add_action("do_exercise", "exercise");
        add_action("do_exercise", "dazuo");
        add_action("do_exercise", "respirate");
        add_action("do_exercise", "tuna");
        add_action("do_exercise", "lian");
        add_action("do_exercise", "practice");
        add_action("do_exercise", "study");
        add_action("do_exercise", "du");
        add_action("do_exercise", "sleep");
}

int do_kill(string arg)
{
        object ob, ob1, ob2, me = this_player();

        if ( !arg || arg == "") return 0;

        if ( !ob=present(arg, environment(me)) ) return 0;
        if ( ob->query("family/family_name") == "灵鹫宫" && me->query("family/family_name") != "灵鹫宫" ) {
           message_vision("$n对著$N喝道：「"+RANK_D->query_rude(ob)+"！今日不是你死就是我活。\n", ob, me);

           if ( ob1=present("mei jian", environment(me)) ) {
                message_vision("$N一声冷笑：大胆狂徒！竟敢在灵鹫宫行凶杀人，当我灵鹫宫好欺负么？\n", ob1);
                ob1->kill_ob(me);
           }
           if ( ob2=present("lan jian", environment(me)) ) {
                message_vision("$N一声冷笑：大胆狂徒！竟敢在灵鹫宫行凶杀人，当我灵鹫宫好欺负么？\n", ob1);
                ob2->kill_ob(me);
           }
           if ( !ob1 ) return 0;
           if ( !ob2 ) return 0;
           return 1;
	} 
}

int do_exercise(string arg)
{
        object me = this_player();

	if ( me->query("job_status")==1)
        {
                tell_object(me, "你还是专心守门吧！\n");
                return 1;
        }
        
        return 0;
}