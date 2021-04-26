//room: /newjob/builder/snmuyuping.c 木鱼坪
//Lara 2001/12/03
inherit ROOM;
#include <ansi.h>
void create()
{        
        set("short", "木鱼坪");
        set("long", @LONG
木鱼坪在神农架并不出名，但却是个砍树伐木的好去处，这里的树木
年龄大都在百年上下，正是小树长成了栋梁。在这里伐木还有个更大的好
处，就是这里靠近河流，砍下的木头可以轻松的漂流到山下。这里平时很
少见到猛兽，只有几只淘气的金丝猴在玩耍。
LONG
        );

        set("exits", ([   
        "north" : __DIR__"snhongping",   
        "east" : __DIR__"sngsmiao",
        ]));
        set("no_clean_up", 0);       
        set("invalid_startroom", 1);       
        set("cost", 1);
        setup();
}
