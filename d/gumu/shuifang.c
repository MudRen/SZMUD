// July 31,2000
// Code by April
// /gumu/shuifang.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short","休息室");

    set("long",@LONG
这是一间石室，房中床榻桌椅，但见室右有榻，室中凌空拉着一条长
绳，窗前小小一石几。室左立着一个粗糙石橱，四壁有一些钩子，不知有
什么用。
LONG);

	set("exits",([ 
		"south" : __DIR__"mudao15",
		]));

	create_door("south", "木门", "north");
	set("no_fight", 1);
	set("sleep_room", 1);
	set("cost",1);
	
	setup();	
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	object *inv;
	int i;

	inv = all_inventory(me);

	if ( dir == "south" )
		for (i=0; i<sizeof(inv); i++) 
			if (inv[i]->is_character())
				return notify_fail("你不能带着其他玩家离开。\n");

	return ::valid_leave(me, dir);
}