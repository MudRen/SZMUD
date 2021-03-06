// Code by ShenZhou
// donglang2.c 东厢走廊
// Jiuer * for door

#include <room.h>

inherit ROOM;

void create()
{
    set("short", "东厢走廊");
    set("long", @LONG
你走在一条幽静的走廊上，隐约可以听到东边传来呼吸声，似乎有人正
在那里练功，北边有一扇门（door ），好象是虚掩着。南边是间竹子扎就的
屋子，十分的素雅，里面飘出一阵阵的茶香，有人轻声细语地不知说些什么，
引得女孩子“吃吃”笑出声来。
LONG
    );

    set("exits", ([
		"south" : __DIR__"chashi",
		"west" : __DIR__"donglang1",
		"north" : __DIR__"xiuxishi1",
    ]));                                                  
   
	create_door("north", "木门", "south", DOOR_CLOSED);

	set("cost", 1);
    setup();
}
