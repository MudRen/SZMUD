// Code of ShenZhou
// liangong1.c ������
// by qfy

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������ǹ���ɽ���������ڹ������ж���ѧ�鼮֮�������ڲ����ر�
���裬��������й�ʱ���ģ������˽��ȡ��������е�����Ϣ�ҡ�
LONG
	);

	set("exits", ([
		"west" : __DIR__"pianting2",
		"east" : __DIR__"nanshi",
		"north" : __DIR__"zoulang2",
	]));


	create_door("north", "ľ��", "south", DOOR_CLOSED);
	create_door("east", "����", "west", DOOR_CLOSED);
	
	set("cost", 0);
	setup();

//      replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if ( me->query("gender") == "Ů��" && dir == "east" && !wizardp(me) )
		return notify_fail("������㣬�����е�����Ϣ�ң�\n");

	return ::valid_leave(me, dir);
}