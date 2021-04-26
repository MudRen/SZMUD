// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
����һ����������ʯ��ֵ���������ͷ���졣������һ��С�ӻ��̡�
LONG
        );
        set("exits", ([
                "west" : __DIR__"lanzhou-ximen",
                "east" : __DIR__"lanzhou",
		"south" :__DIR__"zahuopu",
		"north" :__DIR__"yangguan",
        ]));
	set("objects", ([
                "/d/village/npc/kid": 2,
	]));
	set("cost", 1);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
