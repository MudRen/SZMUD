// Code of ShenZhou
// /d/dali/chhill5.c

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "茶花山南");
        set("long", @LONG
这儿是茶花山的南面，仍然有大量的茶花盛开着。但显然不如山上的
品种好了，都是凡品。
LONG
        );

        set("exits", ([
                "westup" : __DIR__"chhill3.c",
                "southeast" : __DIR__"shilin6.c",
        ]));

        set("cost", 2);
        set("fengamount", 3 + random(3));
        set("outdoors", "dali");
        setup();
        replace_program(ROOM);
}
