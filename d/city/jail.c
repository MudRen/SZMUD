// Code of ShenZhou
// Room: /city/bingqiku.c
// YZC 1995/12/04 
//Jay 2/4/97

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǽ�����ԼĪ���ɼ�����һ���ʯ�ң�ǽ�ںͶ��嶼�Ǵ�ʯ������
ǽ�������һֻ��Ͱ�������ŵ��ľ��ǳ�����ù����������ǽ�ϵ�С����
ȥ�����Լ������ָ���һ�ǡ�
LONG
	);

	set("exits", ([
		"east" : __DIR__"bingyin",
	]));
	set("objects", ([
                __DIR__"npc/dingdian" : 1,
        ]));

	create_door("east", "����", "west", DOOR_CLOSED);
	set("cost", 0);
	setup();
	replace_program(ROOM);
}

