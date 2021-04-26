// July 31,2000
// Code by April
// d/gumu/shishi5.c

inherit ROOM;

void create()
{
        set("short","通道");

        set("long",@LONG
这里漆黑一团，通道细窄狭长，你往东西两头乱爬了良久，始终不
到尽头，地下却越来越平。猛听得左首传来一阵大笑之声。
LONG);

	 set("exits",([ 
	//	"east" : __DIR__"shandong",
		"west" : __DIR__"shiku",
		 ]));
	  
	 set("cost",1);
     setup();
}

void init()
{
	add_action("do_pa","pa");
}

int do_pa(string arg)
{
	object me = this_player();
	
	if ( !arg && arg != "east")
		return notify_fail("你要干什么？\n");

	if ( arg == "east") {	
		message_vision("$N曲膝向外面爬去。\n", me);	
		me->move(__DIR__"shandong");
	//	me->delete_temp("marks/ok");
		message_vision("$N爬行了一阵，渐渐爬回山洞。\n", me);
		return 1;
	}
    return 0;
}
