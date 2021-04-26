
// Filename:   /d/jueqinggu/sleeproom2.c 女睡房
// Program:    Jiuer
// Date:       Aug 15, 2001

#include <room.h>
inherit ROOM;

void create()
{
		  set("short","女睡房");

		  set("long",@LONG
这里是水仙山庄女弟子的休息室，地下只是几张草席。桌上花瓶
里插着几枝情花，东面一扇小窗。外面是水塘。
LONG);
	  
	  set("sleep_room", 1);

	  set("exits",([ 
		  "north" : __DIR__"changlang6",
		  ]));
	  
	  set("no_fight", 1);
	  create_door("north", "木门", "south",DOOR_CLOSED);

	  set("cost",1);
	  setup();

}

int valid_leave(object me, string dir)
{
        object *inv;
        int i;


        inv = all_inventory(me);

        if ( dir == "north" ) {
                for (i=0; i<sizeof(inv); i++) {
                        if (inv[i]->is_character())
                        return notify_fail("你不能带着其他玩家离开。\n");
                }
        }

        return ::valid_leave(me, dir);
}