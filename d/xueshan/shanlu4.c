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
                "north" : __DIR__"shanlu1",
                "southup" : __DIR__"shanlu5",
        ]));


	set("cost", 3);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
