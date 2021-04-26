#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��Ϣ��");
        set("long", @LONG
���Ǽ���������᷿�����Ŵ������ţ����ߺܻ谵������������ֻ
���м����һ����ʰ����������Ĵ󴲣����ž�������˯�⡣
LONG
        );
        set("sleep_room", 1);
		set("exits",([ 
			"south" : __DIR__"donglang2",
			 ]));
	    create_door("south", "ľ��", "north", DOOR_CLOSED);
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
					return notify_fail("�㲻�ܴ�����������뿪��\n");
			}
		}
		return ::valid_leave(me, dir);
}

