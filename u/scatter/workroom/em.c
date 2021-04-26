// Room: menpai
// V. 1.0
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", HIM"峨嵋笔记室"NOR);
        set("long", @LONG
这里就是分冥子放笔记的地方, 通常玩家说的建议或是
沟通过程都会在这里写下笔记. 这里可以往外走就可以回到
笔记房.
LONG
        );

        set("exits", ([ /* sizeof() == 3 */
                                  "out" : "/u/scatter/note",
]));      
        set("no_clean_up", 0);
        set("outdoors", "beijing");
        set("cost", 2);

        setup();
                "/clone/board/scem"->foo();
        replace_program(ROOM);
}

