
// Filename:   /d/jueqinggu/sleeproom2.c Ů˯��
// Program:    Jiuer
// Date:       Aug 15, 2001

#include <room.h>
inherit ROOM;

void create()
{
		  set("short","Ů˯��");

		  set("long",@LONG
������ˮ��ɽׯŮ���ӵ���Ϣ�ң�����ֻ�Ǽ��Ų�ϯ�����ϻ�ƿ
����ż�֦�黨������һ��С����������ˮ����
LONG);
	  
	  set("sleep_room", 1);

	  set("exits",([ 
		  "north" : __DIR__"changlang6",
		  ]));
	  
	  set("no_fight", 1);
	  create_door("north", "ľ��", "south",DOOR_CLOSED);

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
                        return notify_fail("�㲻�ܴ�����������뿪��\n");
                }
        }

        return ::valid_leave(me, dir);
}