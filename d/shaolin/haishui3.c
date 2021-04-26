// ROOM: /d/shaolin/hanshui3.c
// Jiuer /8/2001

#include <ansi.h>
#include "d/shaolin/npc/yaoshui.h";inherit ROOM;

void create()
{
        set("short", "汉水岸边");
        set("long", @LONG
这里是汉水岸边，因为地势平坦开阔的缘故，这里的水流显得缓和
了许多，所以这里的河水看上去清澈干净。南阳城的居民都在这里
挑水喝，岸边还有几个农村妇女蹲着洗衣服。
LONG );

        set("exits", ([ /* sizeof() == 2 */
                "east" : __DIR__"hanshui2",
                "northup" : __DIR__"shanlu1",
                ]));

        set("cost",0);
        set("outdoors", "shaolin");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


