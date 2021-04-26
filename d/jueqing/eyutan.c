// Filename:   /d/jueqing/eyutan.c 鳄鱼潭
// Jiuer, Aug 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short",HIC"鳄鱼潭"NOR);
	set("long",@LONG
这是一个又大又深的潭，潭内黑得看不清楚，潭面上隐隐地漂浮着
一些东西，潭水冻得你直打冷战，西面山下好象有个山洞，你快游
(swim)过去看看吧。
LONG);
	set("objects" , ([
		"/d/jueqing/npc/crocodile": 1,
		]));
	set("resource/water", 1);	
	set("cost",3);

	setup();	
}

void init()
{ 
	add_action("do_swim","swim");
}

int do_swim(string arg)
{
        object me = this_player();
        int cost;


        if(me->is_busy())
			return notify_fail("你还在忙着呢。\n");

        //cost = (200-me->query_skill("swimming",1))/10;
        //if ( cost<3 )cost = 3;
        //me->add("jingli",-cost);
        //me->improve_skill( "swimming",random( me->query("con",1)/2 ) );
        me->add("jingli", -200);
        me->start_busy(random(3));

	if( !arg || arg ==" ")
	return notify_fail("你只能往西边游！\n");
        if (arg == "east")
			return notify_fail("你已经在潭东边了，洞口在西边。\n");
	
		if(arg == "west")
		{
			message_vision( HIY"\n$N在鳄鱼潭中拼命划水，往西游了起来。\n"NOR, me);
			me->move(__DIR__"shandong",5,me);
			message_vision( HIY"\n$N游了过来。\n"NOR, me);
			return 1;	
		}		
}

