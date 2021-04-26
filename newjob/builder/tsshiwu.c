//room: /newjob/builder/tsshiwu.c 泰山石屋
//Lara 2001/12/09
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "石屋");
        set("long", @LONG
一间不起眼的小屋，整座屋子全部由石头建成。屋子里积满了灰尘，
看来好久没人居住了。地上有一些破烂的东西，好象是某种工具，但看不
出是派什么用场的。据说有人曾在这看到过一个神秘的老人。
LONG
        );

        set("exits", ([        
        "west" : __DIR__"tshgslu",
        ]));
        set("no_clean_up", 0);        
        set("invalid_startroom", 1);       
        set("cost", 1);
        setup();
}
