// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "祭祀场");
        set("long", @LONG
这里是雪山的祭祀场。由于近来法轮寺里的喇嘛越来越多，法事也越来
越多，所以雪山寺就兴建了专门祭祀用的广场，并且新架设两座法坛，即使
如此这里仍然显得很空旷，四周笼罩着一股肃穆的气氛。
LONG
        );
        set("exits", ([
                "east" : __DIR__"jisichang1.c",

        ]));

        set("objects", ([
                __DIR__"npc/fsgelun" : 1,
                __DIR__"obj/jitan5" : 1,
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
