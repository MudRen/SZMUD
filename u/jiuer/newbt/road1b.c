// Code of ShenZhou
// jiuer 6/2002
// d/baituo/road1b.c

inherit ROOM;

void create()
{
	set("short", "小径");
	set("long", @LONG
一条满地沙石的小径，北边通往山庄的前院，南边是一条小径。
LONG
	);
	set("exits", ([ 
	    "south" : __DIR__"road2",
		"north" : __DIR__"road1a",
		"east" : __DIR__"barn3a",
	]));

	create_door("east", "木门", "west");

	set("outdoors","baituo");
	set("cost", 1);
	setup();
	replace_program(ROOM);
}
