// À’√Œ‹∞(Athena)
// Room£∫/u/athena/ceshi.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "≤‚ ‘ “");
        set("long", @LONG
°ÿ®T®p®T®T®T-
LONG
        );

              set("exits", ([ /* sizeof() == 3 */ 
                        "down"  : "/d/city/kedian", 
        ]));
        set("objects", ([
               __DIR__"npc/parrot" : 1, 
        ]));
}
