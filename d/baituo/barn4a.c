// Code of ShenZhou
// room: /d/baituo/barn4a.c
// Jiuer

inherit ROOM;

void create()
{
	set("short", "蛇室");
	set("long", @LONG
这是白驼山庄的蛇室，白驼弟子常在这里驯养怪蛇，东北角有个小门
通到外面的空地。
LONG
	);
	set("exits", ([ 
		"down" : __DIR__"barn4b",
		"northeast" : __DIR__"kongdi1",
	]));

	create_door("northeast", "竹门", "southwest");

	replace_program(ROOM);
	set("cost", 0);
	setup();
}
