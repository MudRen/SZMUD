// Code of ShenZhou
// room: /d/baituo/barn1a.c
// Jiuer

inherit ROOM;

void create()
{
	set("short", "蛇室");
	set("long", @LONG
这是白驼山庄的蛇室，白驼弟子常在这里驯养怪蛇，旁边有个小门。
LONG
	);
	set("exits", ([ 
		"north" : __DIR__"barn1b",
		"west" : __DIR__"road1",
	]));
	create_door("west", "木门", "east");

	replace_program(ROOM);
	set("cost", 1);
	setup();
}
