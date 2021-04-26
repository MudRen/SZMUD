// Filename:   /d/jueqinggu/sleeproom1.c 男睡房
// Program:    Jiuer
// Date:       Aug 15, 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short","男睡房");
	
	set("long",@LONG
这里是绝情谷水仙山庄男弟子的休息室，地下只是几张草席。西
首一扇小窗。窗外面是后花园。
LONG);
	  
	  set("sleep_room", 1);
	  set("exits",([ 
		"south" : __DIR__"shishi3",
			 ]));
	  create_door("south", "木门", "north", DOOR_CLOSED);
	  set("no_fight", 1);
	  set("cost",1);
	  setup();
	 // replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        object *inv;
        int i;

        inv = all_inventory(me);

        if ( dir == "south" ) {
			for (i=0; i<sizeof(inv); i++) {
				if (inv[i]->is_character())
					return notify_fail("你不能带着其他玩家离开。\n");
			}
		}
		return ::valid_leave(me, dir);
}