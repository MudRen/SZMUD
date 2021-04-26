//room: /newjob/builder/tsqslu.c 泰山花岗石路
//Lara 2001/12/09
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "花岗石路");
        set("long", @LONG
这条路全部由花岗石铺成，坚硬花岗石的路面踩着相当踏实。由于花
岗石比较稀少，因此整条路由不同大小的花岗石分几段铺成。路的尽头有
一间小屋，不过平时好象没人居住。
LONG
        );

        set("exits", ([        
        "west" : __DIR__"tsqslu",
        "east" : __DIR__"tsshiwu",
        "north" : __DIR__"tszschangn",
        "south" : __DIR__"tszschangs",
        ]));
        set("no_clean_up", 0);        
        set("invalid_startroom", 1);       
        set("cost", 1);
        setup();
}
