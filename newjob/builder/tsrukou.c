//room: /newjob/builder/tsrukou.c 泰山采石场入口
//Lara 2001/12/08
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "入口");
        set("long", @LONG
这是泰山脚下一条偏僻的小路，小路蜿蜒曲折，不知通向何处。路边
挂着一块长满青苔的牌子 (board)。
LONG
        );

        set("exits", ([        
        "east" : __DIR__"tsxslu",
        "west" : "/d/taishan/daizong",
        ]));
        set("no_clean_up", 0);
        set("item_desc", ([
              "board" : YEL"◇◇◇◇泰山采石场◇◇◇◇\n"+NOR       
        ]));
        set("invalid_startroom", 1);       
        set("cost", 1);
        setup();
}
