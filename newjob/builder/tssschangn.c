//room: /newjob/builder/tssschangn.c 泰山碎石场（北）
//Lara 2001/12/08
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "碎石场");
        set("long", @LONG
这里到处都是山上采石和运输过程中有意或无意留下的碎石，由于碎
石无甚用处，因此这里的碎石越积越多。成年累月的积累下来，这里的碎
石已经堆积成了小山，逐渐有堵塞采石场下山之路的趋势。
LONG
        );

        set("exits", ([        
        "south" : __DIR__"tsxslu",
        "east" : __DIR__"tsqschangn",
        ]));
        set("no_clean_up", 0);        
        set("invalid_startroom", 1);       
        set("cost", 1);
        setup();
}
