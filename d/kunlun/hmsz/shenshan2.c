// shenshan2.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
                  set("short", "昆仑山深处");
                  set("long",@long
这里黄沙扑面，寒风透骨，却也着实难熬,你在昆仑山中转来转去，
,四面都是荒凉的戈壁滩和乱石堆,再也找不到出山的途径。
long);
                 set("exits",([
"east" : __DIR__"shenshan3",
"south" : __DIR__"shenshan2",
"west" : __DIR__"shenshan1",
"north" : __DIR__"shenshan2",
]));

set("objects",([
                __DIR__"npc/gundog" :  2,
]));
set("outdoors", "kunlun");
        set("cost", 5);
setup();
replace_program(ROOM);
}
