// Code of ShenZhou
// Room: /d/xingxiu/gcdoor.c
// Date: June 30, 96   Jay
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�Թ�����");
	set("long", @LONG
ת����һ����ľ��ֻ������һ��ʯɽ��Ƕ�����������Ĵ���(door)��
��������߰ߣ�������ʱ�Ѿõľ��
LONG
	);
	switch(random(2)){
        case 0:
                set("objects", ([ "/d/xingxiu/npc/scorpion" : 1,
				  "/d/xingxiu/npc/spider2" : 1]));
                break;
        default:
                set("objects", ([ "/d/xingxiu/npc/spider2" : 1]));
                break;
	}
	set("item_desc", ([
		"door" : "�����ƺ���δ������\n",
	]));

	set("exits", ([
		"southeast" : __DIR__"shangu",
                "enter" : __DIR__"gcmaze1",
	]));
	create_door("enter","������","out",DOOR_CLOSED);

	set("cost", 1);
	setup();
	set("outdoors", "xingxiu");
	replace_program(ROOM);
}

