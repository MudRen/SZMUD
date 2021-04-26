//room: /newjob/builder/snrukou.c 神农架林场入口
//Lara 2001/11/10
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "入口");
        set("long", @LONG
眼前就是神农架了，到处都是高大茂密的树木，地面上铺着一层厚厚
的落叶，软绵绵的，踩着相当舒服。路边一颗四人合围的大树上挂着一块
牌子 (board)。
LONG
        );

        set("exits", ([        
        "east" : __DIR__"snhongping",
        "west" : "/d/foshan/road2",
        ]));
        set("no_clean_up", 0);
        set("item_desc", ([
              "board" : HIG"∽∽∽∽神农架∽∽∽∽\n"+NOR       
        ]));
        set("invalid_startroom", 1);       
        set("cost", 1);
        setup();
}
