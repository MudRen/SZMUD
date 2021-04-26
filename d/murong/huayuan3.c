// Code of ShenZhou
// Room: /d/murong/huayuan3
//arthurgu /1999.9

#include "room.h"
inherit ROOM;

void create()
{
	set("short", "后花院");
	set("long", @LONG
   这里有个小池塘，不时传出青哇的鸣叫。苏州一带的蛙
个子并不大，但味道鲜明，所以经常有人捕捉。花园的南端
有扇小门。
LONG
	);
	set("cost", 1);
	set("outdoors", "murong");
	set("exits", ([ 
        "out" : __DIR__"lianwu1",
        "west" : __DIR__"huayuan1",
                      ]));
	set("no_clean_up", 0);
        create_door("out","木门","enter", DOOR_CLOSED);
	setup();

	replace_program(ROOM);
}
