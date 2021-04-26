//room: /newjob/builder/cbrukou.c 长白山林场入口
//Lara 2001/11/10
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "入口");
        set("long", @LONG
这里是满天星北边的一块小平地，与满天星不同，这里偶尔能看到几
株小树了，路边一株稍大一点的树上挂着一块牌子 (board)。
LONG
        );

        set("exits", ([        
        "east" : __DIR__"cbguanmue",
        "south" : "/d/changbai/mantx",
        "west" : __DIR__"cbguanmuw",
        "north" : __DIR__"cbguanmu",
        ]));
        set("no_clean_up", 0);
        set("item_desc", ([
              "board" : HIY"※※※※※※长白山林场※※※※※※\n"+NOR       
        ]));
        set("invalid_startroom", 1);       
        set("cost", 1);
        setup();
}
