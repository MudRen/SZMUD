// Code of ShenZhou
// room: /d/baituo/barn2
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
		"west" : __DIR__"barn2b",
	    "east" : __DIR__"btbarn",
	]));
	
	create_door("east", "木门", "west");

	replace_program(ROOM);
	set("cost", 0);
	setup();
}
