//room: /newjob/builder/tsqslu.c 泰山青石路
//Lara 2001/12/08
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "青石路");
        set("long", @LONG
一条整齐的青石路曲折的顺山势而上。细看这些铺路的青石，大小、
形状、厚度、色泽都非常一致，由于走的人多，路面已被摩得十分光滑。
路边有突出的石头，经常会在路面上固定之处滴水，在这些路面上就可以
看到一个凹下的小坑，真所谓“水滴石穿”也。
LONG
        );

        set("exits", ([        
        "west" : __DIR__"tsxslu",
        "east" : __DIR__"tshgslu",
        "north" : __DIR__"tsqschangn",
        "south" : __DIR__"tsqschangs",
        ]));
        set("no_clean_up", 0);        
        set("invalid_startroom", 1);       
        set("cost", 1);
        setup();
}
