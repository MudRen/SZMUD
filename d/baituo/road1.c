// Code of ShenZhou
// 白驼改版
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "小径");
	set("long", @LONG
一条幽深的小径，北面传出「嘶嘶」的声响。东面有个窖棚。
LONG
	);
	set("exits", ([ 
	    "north" : __DIR__"barn",
		"south" : __DIR__"btyard",
		"east" : __DIR__"barn1a",
	]));
	
	create_door("east", "木门", "west");

	set("outdoors","baituo");
	replace_program(ROOM);
	set("cost", 1);
	setup();
}
