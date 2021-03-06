// /d/jueqing/garden.c  花园
// By jiuer

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIR"花园"NOR);
	set("long",@LONG 
只觉阳光耀眼，花香扑鼻，竟是别有天地，游目四顾，只见繁花青
草，如同一个极大的花园，然花影不动，幽谷无人。但见十余丈外有几
间茅屋。
LONG);
	
	set("exits",([ 
		"east" : __DIR__"maowu",
		"westdown" : __DIR__"bingyao",
		]));
	set("outdoors","jueqing");

	set("cost",1);
	setup();
}

int do_dive(string arg)
{
	object me = this_player();
	if(!arg||arg !="in")
		return 0;

	if(arg == "in") 
	{
		message_vision("$N纵身入潭，直往深处潜去。\n",me);
		me->add("jingli",-50);
		message_vision("$N急沉而下，猛地里只觉一股急流卷冲过去，光亮处果然是一洞。\n",me);
		set("exits/up",__DIR__"bingyao");
		remove_call_out("close_door");
		call_out("close_door",5,me);
		return 2;
	}
}

void close_door()
{
	tell_room(this_object(),"$N潜入冰窖，回到潭边。\n");
	delete("exits/up");
}