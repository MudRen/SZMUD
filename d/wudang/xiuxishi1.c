#include <room.h>
inherit ROOM;

void create()
{
        set("short", "休息室");
        set("long", @LONG
这是间整洁的男厢房，因门窗常闭着，光线很昏暗。房里别无他物，只
有中间放着一张收拾得舒舒服服的大床，看着就让人有睡意。
LONG
        );
        set("sleep_room", 1);
		set("exits",([ 
			"south" : __DIR__"donglang2",
			 ]));
	    create_door("south", "木门", "north", DOOR_CLOSED);
        set("no_fight", 1);
		set("cost", 0);
        setup();
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

