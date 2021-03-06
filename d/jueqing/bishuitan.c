// /d/jueqing/bishuitan.c 碧水潭
// By jiuer

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIY"碧水潭"NOR);
	set("long",@LONG 
这里竟是一个水潭。从数百丈高处跃将下来，冲力何等猛烈，笔直
的坠将下去，也不知沉入水中多深。
LONG);
	set("outdoors","jueqing");

	set("cost",1);
	setup();
}

void init()
{
	add_action("do_dive","dive");
	add_action("do_climb","climb");
}

int do_dive(string arg)
{
	object me = this_player();
	if(!arg)
		return 0;

	if(arg == "down") 
	{
		message_vision("$N纵身入潭，直往深处潜去。\n",me);
		me->add("jingli",-50);
		message_vision("$N急沉而下，猛地里只觉一股急流卷冲过去，光亮处果然是一洞。\n",me);
		set("exits/enter",__DIR__"bingyao");
		remove_call_out("close_door");
		call_out("close_door",5,me);
		return 1;
	}
}

int do_climb(string arg)
{
	object me = this_player();
	
	if(arg =="up")
	{ 
		message_vision("$N湿渌渌的从潭水里爬上潭来。\n",me);
		me->move(__DIR__"tanbian");
		return 1;
	} 
	else
		return 0;
}
void close_door()
{
	tell_room(this_object(),"水深处浮力奇强，立时身不由主的被浮力托了上来。\n");
	delete("exits/enter");
}
