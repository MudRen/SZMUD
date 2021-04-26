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
���裬��������й�ʱ���ģ������˽��ȡ��ϱ����е�����Ϣ�ң�������
��ľ��ͨ���ȡ�
LONG
	);

	set("exits", ([
		"west" : __DIR__"zoulang1",
		"south" : __DIR__"nanshi",
		"north" : __DIR__"donglang",
	]));


	create_door("north", "ľ��", "south", DOOR_CLOSED);
	create_door("south", "����", "north", DOOR_CLOSED);
	
	set("cost", 0);
	setup();

//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ( (!myfam || myfam["family_name"] != "��ɽ��") && dir == "south" )
                return notify_fail("��ɽ������ͣ��㲻��ס�����\n");

        if ( me->query("gender") == "Ů��" && dir == "south" && !wizardp(me) )
                return notify_fail("������㣬�����е�����Ϣ�ң�\n");

        if ( me->query("gender") == "����" && dir == "south" )
                return notify_fail("�㲻��ס�����\n");

        return ::valid_leave(me, dir);
}
