// Code of ShenZhou
// daxiong.c ���۱���
// Shan: 96/06/29

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "�����ִ��۱���");
	set("long", @LONG
���Ƕ���ɽ�����ֵĴ��۱�����й���������������һȺ����Сʦ̫��
�ڵ����о��������е�С��ͨ����
LONG
	);

	set("exits", ([
		"northdown" : __DIR__"hz_guangchang",
		"south" : __DIR__"hz_back",
	]));

        create_door("south", "ľ��", "north", DOOR_CLOSED);

        set("valid_startroom",1);

	set("cost", 0);
	setup();
//	replace_program(ROOM);
}
