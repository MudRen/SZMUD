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
���裬��������й�ʱ���ģ������˽��ȡ��ϱ���Ů������Ϣ�ң�������
������ͨ�����ȡ�
LONG
	);

	set("exits", ([
		"east" : __DIR__"zoulang1",
		"north" : __DIR__"xilang",
		"south" : __DIR__"nushi",
	]));

	set("cost", 0);
	setup();

	create_door("north", "����", "south", DOOR_CLOSED);
	create_door("south", "����", "north", DOOR_CLOSED);

//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
    	mapping myfam;
    	myfam = (mapping)me->query("family");

    	if ( (!myfam || myfam["family_name"] != "��ɽ��") && dir == "south" )
		return notify_fail("��ɽ������ͣ��㲻��ס�����\n");

	if ( me->query("gender") == "����" && dir == "south" && !wizardp(me) )
		return notify_fail("������㣬����Ů������Ϣ�ң�\n");

	if ( me->query("gender") == "����" && dir == "south" )
		return notify_fail("�㲻��ס�����\n");

	return ::valid_leave(me, dir);
}
