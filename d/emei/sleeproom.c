// Code of ShenZhou
// sleeproom.c ��������Ϣ��
// Shan: 96/06/22

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��������Ϣ��");
	set("long", @LONG
�����Ƕ��һ����ֵ���Ϣ�ҡ���������������������������˺ܶ�ľ����
�м���ҹ�����ֵ�Сʦ̫����˯����
������Ϣ�������������
LONG
	);
	set("exits", ([
		"north" : __DIR__"hz_chanfang",
	]));

        set("item_desc",([
                "door"          :       (: look_door :),
        ]));

        create_door("north", "ľ��", "south", DOOR_CLOSED);

	set("no_fight", 1);
	set("sleep_room", 1);

	set("cost", 0);
	setup();
//	replace_program(ROOM);

}

