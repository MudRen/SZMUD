// Filename:   /d/jueqinggu/shishi3.c 石室3
// Code:       Jiuer
// Date:       Aug 15, 2001

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
		  set("short","石室");
		  set("long",@LONG
这是一间不大的石室，里面空空荡荡的，不知道主人派这房什么
用场。石室北边是男睡房。石室外面是条长长的走廊。
LONG);
		  set("exits",([ 
		      "west" : __DIR__"changlang6",
			  "north" : __DIR__"sleeproom1",
			 ]));
		  create_door("north", "木门", "south", DOOR_CLOSED);

	  set("cost",1);
	  setup();	

}

int valid_leave(object me, string dir)
{
	if ( me->query("gender") == "女性" && dir == "north" && !wizardp(me) )
		return notify_fail("看清楚点，那是男睡房！\n");

        return ::valid_leave(me, dir);
}