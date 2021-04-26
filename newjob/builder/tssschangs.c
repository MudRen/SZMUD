//room: /newjob/builder/tssschangs.c 泰山碎石场（南）
//Lara 2001/12/08
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "碎石场");
        set("long", @LONG
这里到处都是山上采石和运输过程中有意或无意留下的碎石，由于碎
石无甚用处，因此这里的碎石越积越多。经常有喜欢石头的文人墨客到这
里来寻宝，据说碎石堆里经常能找到象鸡血石这样的宝贝。
LONG
        );

        set("exits", ([        
        "north" : __DIR__"tsxslu",
        "east" : __DIR__"tsqschangs",
        ]));
        set("no_clean_up", 0);        
        set("invalid_startroom", 1);       
        set("cost", 1);
        setup();
}
