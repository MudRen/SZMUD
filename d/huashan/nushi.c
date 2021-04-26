// Code of ShenZhou
// Room: nushi.c ��ɽŮ������Ϣ��
// qfy July 7, 1996 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "Ů������Ϣ��");
	set("long", @LONG
���ǻ�ɽŮ���ӵ���Ϣ�ҡ���������������򵥡���ǽ���м���ľ����
���Ŵ�����һ�����ӡ������и���ױ̨������������������
LONG
	);

	set("sleep_room", 1);
	set("no_fight", 1);

	set("exits", ([
	    "east" : __DIR__"liangong2",
	    "north" : __DIR__"zoulang5",
	]));

	create_door("north", "ľ��", "south", DOOR_CLOSED);
	create_door("east", "����", "west", DOOR_CLOSED);

	set("cost", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	object *inv;
	int i;

	inv = all_inventory(me);

	if ( dir == "east" || dir == "north" ) {
		for (i=0; i<sizeof(inv); i++) {
			if (inv[i]->is_character())
			return notify_fail("�㲻�ܴ�����������뿪��Ϣ�ҡ�\n");
		}
	}

	return ::valid_leave(me, dir);
}