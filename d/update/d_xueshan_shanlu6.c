// Code of ShenZhou
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
ɽ·Խ??Խխ????????????ǰ???ֳַ??˼?????·?????߾????????ĳ????ǡ?
LONG
        );
        set("exits", ([
                "northdown" : __DIR__"shanlu5",
                "east" : "/d/changan/ximen",
		"westup" : __DIR__"shanlu2",
		"southup" :__DIR__"shanlu7",
        ]));


	set("cost", 3);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
