// Filename:   /d/jueqinggu/changlang6.c 长廊6
// Code:       Jiuer
// Date:       Aug 15, 2001

#include <room.h>
inherit ROOM;

void create()
{
		  set("short","长廊");
		  set("long",@LONG
这是一条长长的走廊，墙壁都是用两尺厚的青石板垒筑而成。南
北墙上均匀地凿嵌着一些小洞，里面摆放着一些灯盏，把长廊照得亮
堂堂的。长廊南侧是女睡房，你走到这儿不觉脚步放轻了许多。
LONG);
		  set("exits",([ 
		      "east" : __DIR__"shishi3",
			  "west" : __DIR__"changlang5",
			  "south" : __DIR__"sleeproom2",
			 ]));
		  create_door("south", "木门", "north",DOOR_CLOSED);
		  set("cost",1);
		  setup();	
}

int valid_leave(object me, string dir)
{
	if ( me->query("gender") == "男性" && dir == "south" && !wizardp(me) )
		return notify_fail("看清楚点，那是女睡房！\n");

        return ::valid_leave(me, dir);
}

