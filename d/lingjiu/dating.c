//ROOM dating.c

inherit ROOM;

void create()
{
	set("short", "独尊厅");
        set("long",@LONG
这就是『灵鹫宫』独尊厅。大厅全是以巨石砌成，石块之间竟无半点
缝隙，令人称奇。厅内矗立着四根石柱，皆为坚硬的花岗石所制。
LONG
	);
        set("exits", ([
		"north" : __DIR__"changl15",
		"south" : __DIR__"damen",
        ]));

	set("objects",([
		CLASS_D("lingjiu")+"/xuzhu" : 1,
	]));
	set("valid_startroom", 1);
	setup();
        "/clone/board/lingjiu_b"->foo();  
}
void init()
{
        add_action("do_kill","kill");
}

int do_kill(string arg)
{
        object ob, ob1, me = this_player();

        if ( !arg || arg == "" || arg == "xu") return 0;


        if ( !ob=present(arg, environment(me)) ) return 0;
        if ( ob->query("family/family_name") == "灵鹫宫" && me->query("family/fa
mily_name") != "灵鹫宫" ) {
           message_vision("$n对著$N喝道：「"+RANK_D->query_rude(ob)+"！今日不是你死就是我活。\n", ob, me);

           if ( ob1=present("xu zhu", environment(me)) ) {
                message_vision("$N一声冷笑：大胆狂徒！竟敢在灵鹫宫行凶杀人，当我灵鹫宫好欺负么？\n", ob1);
                ob1->kill_ob(me);
           }
           if ( !ob1 ) return 0;
           return 1;
	} 
}
