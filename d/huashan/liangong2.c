// Code of ShenZhou
// liangong2.c ������
// by qfy

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������ǹ���ɽ���������ڹ������ж���ѧ�鼮֮�������ڲ����ر�
���裬��������й�ʱ���ģ������˽��ȡ�������Ů������Ϣ�ҡ�
LONG
	);

	set("exits", ([
		"east" : __DIR__"pianting2",
		"west" : __DIR__"nushi",
		"north" : __DIR__"zoulang4",
	]));

	set("cost", 0);
	setup();

	create_door("north", "ľ��", "south", DOOR_CLOSED);
	create_door("west", "����", "east", DOOR_CLOSED);

//      replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ( me->query("gender") == "����" && dir == "west" && !wizardp(me) )
		return notify_fail("������㣬����Ů������Ϣ�ң�\n");

	return ::valid_leave(me, dir);
}
