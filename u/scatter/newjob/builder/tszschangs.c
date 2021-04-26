//room: /newjob/builder/tszschangs.c 泰山重石场（南）
//Lara 2001/12/09
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "重石场");
        set("long", @LONG
这里的石头十分坚硬、沉重，开采起来相当费劲。一般是由有经验的
老手带领一批年轻人进行开采，大家必须分工明确，才能做到有条不紊。
这里大都是花岗石、汉白玉等名贵的石料，运气好的话还能发现玉石。
LONG
        );

        set("exits", ([        
        "north" : __DIR__"tshgslu",
        "west" : __DIR__"tsqschangs",
        ]));
        set("no_clean_up", 0);        
        set("invalid_startroom", 1);       
        set("cost", 1);
        setup();
}
