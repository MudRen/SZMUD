// Code of ShenZhou
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
������һɽ·�ϣ�������һ����Сɽ��
LONG
        );
        set("exits", ([
                "east" : __DIR__"shixia",
		"south" : __DIR__"shanlu4",
        ]));


	set("cost", 2);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
