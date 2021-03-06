// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "前偏院");
        set("long", @LONG
这里是雪山的前偏院。由于近来法轮寺里的喇嘛越来越多，法事也越来
越多，所以便在前院与菩提塔之间的偏院新搭了两座法坛。寺里的小喇嘛经
常在这里做法事。
LONG
        );
        set("exits", ([
                "east" : __DIR__"frontyard",
                "north" : __DIR__"frontyard3",
                "west" : __DIR__"putita",
        ]));

        set("objects", ([
                __DIR__"npc/fsgelun" : 1,
                __DIR__"obj/jitan2" : 1,
        ]));

        set("cost", 1);
        setup();
        set("outdoors","qilian-shan");
}
int valid_leave(object me, string dir)
{
        object ob;
        ob=(present("fa tan", (environment(me))));
        if ( me->query("name") == ob->query("pending")
        && ob->query("burning"))
                return notify_fail("你法事没做完就想走？\n");
        return ::valid_leave(me, dir);
}
