// Code of ShenZhou
// 清波门
// Dong  11/03/1996.
// nta:  Need to add some npc here.
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", CYN"清波门"NOR);
    set("long", @LONG
园门口有一大门楼，大匾上刻着“清波门”。门楼下站着几个嘻
嘻哈哈的少女，惹人坠步相观。再往西就进了聚景园，往东便回到大路.
LONG);

    set("exits", ([ /* sizeof() == 2 */ 
                   "east" : __DIR__"road25", 
                   "west" : __DIR__"jujing2", 

                 ])
       );
	set("objects",([
                "/d/village/npc/girl" : 2,
        ]));
	set("cost", 1);
     set("fjing", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
