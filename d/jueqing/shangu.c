// Filename:   /d/jueqinggu/shangu.c 山谷
// Jiuer Aug 15, 2001
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","山谷");
	set("long",@LONG
这里溪流曲折，船儿(row raft)七转八弯进了山谷，两边山峰峭立，
地势十分险峻。站在高冈，俯视幽谷，但见树木森森，晨光照耀，满眼
青翠，飘飘荡荡的，宛似身在云端。
LONG);

	  set("outdoors","jueqing");
	  set("resource/water", 1);
	  set("cost",1);
	  
	  setup();	
}

void init()
{
	add_action("do_row","row");
	add_action("do_drift","drift");
}

int do_row(string arg)
{
    object ob, me = this_player();

	if(!arg||arg=="")
		return 0;
	if(arg =="raft") {
		
		message_vision("$N使劲地把筏子向前划呀！划呀！\n\n", me);
		me->receive_damage("jingli", 10, "落水淹死了");
		message_vision("$N划着筏子驶进了山谷里。\n\n",me);
		me->move("/d/jueqing/valley");
		return 1;
 }
 else
	 return notify_fail("你要干什么？\n");
}

int do_drift()
{
	object me = this_player();
	message_vision(HIW"$N握紧船弦，皮筏顺河颠簸漂流而下。\n"NOR,me);
	me->move("/d/jueqing/dongkou");
	message_vision(HIW"河水卷着$N的皮筏，颠簸着从上游漂流而下。\n"NOR,me);
	return 1;
}
