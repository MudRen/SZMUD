// Filename:   /d/jueqinggu/sleeproom1.c ��˯��
// Program:    Jiuer
// Date:       Aug 15, 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short","��˯��");
	
	set("long",@LONG
�����Ǿ����ˮ��ɽׯ�е��ӵ���Ϣ�ң�����ֻ�Ǽ��Ų�ϯ����
��һ��С�����������Ǻ�԰��
LONG);
	  
	  set("sleep_room", 1);
	  set("exits",([ 
		"south" : __DIR__"shishi3",
			 ]));
	  create_door("south", "ľ��", "north", DOOR_CLOSED);
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
					return notify_fail("�㲻�ܴ�����������뿪��\n");
			}
		}
		return ::valid_leave(me, dir);
}