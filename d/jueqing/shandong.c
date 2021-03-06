// Filename:   /d/jueqinggu/shandong.c 山洞
// Jiuer Aug 15, 2001
#include <ansi.h>
inherit ROOM;
int do_pa(string arg);
void create()
{
		  set("short","大山洞");
		  set("long",@LONG
这是潭边的一个大山洞，洞口极窄，只得膝行而爬，由于鳄潭水气
蒸浸，洞中潮湿滑溜，腥臭难闻。
LONG);
		
		  set("cost",1);
		  setup();	
}

void init()
{
	add_action("do_pa","pa");
	add_action("do_swim","swim");
}

int do_pa(string arg)
{
	object me = this_player();
	
	if ( !arg && arg != "west")
		return notify_fail("你只能向西爬。\n");

	if ( arg == "west") {	
		message_vision("$N曲膝向里面爬去。\n", me);	
		me->move(__DIR__"tongdao");
	//	me->delete_temp("marks/ok");
		message_vision("$N爬行了一阵，隧洞渐宽，已可直立行走。\n", me);
		return 1;
	}
    return 0;
}

int do_swim(string arg)
{
        object me = this_player();
        int cost;

        if(me->is_busy())
                return notify_fail("你还在忙着呢。\n");

        cost = (200-me->query_skill("swimming",1))/10;
        if ( cost<3 )cost = 3;
        me->add("jingli",-cost);
     // me->improve_skill( "swimming",random( me->query("con",1)/2 ) );
        me->start_busy(random(3));

        if (arg == "west")
        {
			return notify_fail("你已经在潭西边上了。\n");
        }
		else if(arg =="east")
		{
			message_vision( HIY"\n$N在鳄鱼潭中拼命划水，往西游了起来。\n"NOR, me);
			me->move("/d/jueqing/eyutan");
			message_vision( HIY"\n$N游了过来。\n"NOR, me);
			return 1;
		}
		return 2;
}

