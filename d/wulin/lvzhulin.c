// room /d/wulin/lvzhulin.c
// Lara 2001/10/13
#include <ansi.h>
inherit ROOM;
void create()
{   
   set("short", "绿竹林");
   set("long", @LONG
你走进了一片青翠欲滴的绿竹林，时而有几只小鸟发出清脆的叫声，
一阵风吹过，竹林发出一阵悦耳动听的“沙沙”声，加上竹林外时断时续
的琴声，形成了一组美妙动听音乐，好个快乐逍遥的所在。
LONG   );

    set("exits", ([
		"north" : __DIR__"xiaowu",
                "south" : __DIR__"houyuan",
    ]));
    
    setup();
}
