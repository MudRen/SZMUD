//room: /newjob/builder/tsqschangn.c 泰山轻石场（南）
//Lara 2001/12/08
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "轻石场");
        set("long", @LONG
这里的石头比较软，重量也比较轻，开采起来比较容易。到这里干活
的一般是经验较浅的年轻工人，往往开采和搬运一起完成。年轻人一边干
活，一边唱着山歌，一片忙忙碌碌。
LONG
        );

        set("exits", ([        
        "north" : __DIR__"tsqslu",
        "west" : __DIR__"tssschangs",
        "east" : __DIR__"tszschangs",
        ]));
        set("no_clean_up", 0);        
        set("invalid_startroom", 1);       
        set("cost", 1);
        setup();
}
