// July 31,2000
// Code by April
// /gumu/shuifang.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short","��Ϣ��");

    set("long",@LONG
����һ��ʯ�ң����д�����Σ�����������齣������������һ����
������ǰССһʯ������������һ���ֲ�ʯ�����ı���һЩ���ӣ���֪��
ʲô�á�
LONG);

	set("exits",([ 
		"south" : __DIR__"mudao15",
		]));

	create_door("south", "ľ��", "north");
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
				return notify_fail("�㲻�ܴ�����������뿪��\n");

	return ::valid_leave(me, dir);
}