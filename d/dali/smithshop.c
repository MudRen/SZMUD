// Code of ShenZhou
inherit ROOM;

void create()
{
        set("short", "铁器铺");
        set("long", @LONG
这里是大理城内贩卖铁器的地方，大理盛产精质铁器，
王城内所买的自然是上品。一个看起来满面精明的南彝商
人正在招揽客人。
LONG
        );

set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dahejie",
]));

        set("objects", ([
                __DIR__"npc/ironsmith" :1,       
 ]));

set("cost", 1);

        setup();
}

int valid_leave(object me, string dir)
{
        if( present("iron smith", me) )
                return notify_fail("你想拐带商人绑票啊？欺负老实人啊！\n");

        return ::valid_leave(me, dir);
}

