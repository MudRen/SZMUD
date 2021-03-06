// Code of ShenZhou
// Room: /d/dali/garden9.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", RED"茶花院"NOR);
	set("long", @LONG
这里满地遍是茶花，五颜六色，绚丽夺人。花丛中时时有
蜜蜂采蜜其间。碎石路边却长了一，两品异种茶花(flower)。
LONG
	);

	set("item_desc", ([
		"flower" : RED"抓破美人脸
白瓣而洒红斑的，叫作“红妆素裹”，百瓣而有一抹绿晕，一
丝红条的叫作“抓破美人脸”。但红丝多了，便是“倚榄娇”了。
"NOR,
]));
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([
		"south" : __DIR__"garden8",
		]));

	set("valid_startroom", 1);

    setup();
}

