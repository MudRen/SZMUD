// Room: scatterLobby

#include <ansi.h>
#include <room.h>


inherit ROOM;

void create()
{
        set("short", HIG"会议室三"NOR);
        set("long", @LONG
这里就是会议室一了.只看见到处都是设计图.不时你还看见
有人在打瞌睡.这间房间的用途是给巫师开会用的.通常一个礼拜
都会开一个检讨会议.往外走就是大厅了.

LONG
        );
        set("exits", ([ /* sizeof() == 3 */
                  "out"  : "/u/scatter/lobby",
]));      
        set("no_clean_up", 0);
        set("outdoors", "beijing");
        set("cost", 2);
//      set("objects", ([
//              "/clone/board/bj_wizb" : 1,
//      ]));

        setup();
        replace_program(ROOM);
}

