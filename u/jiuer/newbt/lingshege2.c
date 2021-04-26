// 灵蛇阁二楼
// jiuer 5/19/2002

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "灵蛇阁二楼");
        set("long", @LONG
这是灵蛇阁二楼，是欧阳锋研读武籍的静室，房中摆设甚是简朴，但
极其干净，房中站立一老仆，他正在收拾静室。
LONG
        );
        set("exits", ([ 
			"down" : __DIR__"lingshege",
        ]));

       // set("objects", ([ 
	//		"/d/baituo/npc/puren" : 1,
	//	]));

	set("cost", 1);        
	setup();
}

int valid_leave(object me, string dir)
{   
	if (me->query("family/family_name")!="白驼山")
	{ 
	   if( present("guaishe", me) && dir == "down")
		   return notify_fail("好端端地你想带怪蛇到哪里去？！\n");
	   if( present("she jing", me) && dir == "down")
		   return notify_fail("蛇经不得带出本室！\n");  
	}
	return ::valid_leave(me,dir);
}


 
