// Code of ShenZhou
// room: /d/baituo/barn5a.c
// Jiuer

inherit ROOM;

void create()
{
	set("short", "蛇室");
	set("long", @LONG
这是白驼山庄的蛇室，白驼弟子常在这里驯养怪蛇，西北角有个小门。
LONG
	);
	set("exits", ([ 
		"northwest" : __DIR__"kongdi1",
		"south" : __DIR__"barn5b",
	]));
	create_door("northwest", "木门", "southeast");

	replace_program(ROOM);
	set("cost", 0);
	setup();
}
