//Cracked by shenzhou
// road3.c

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
你走在一条青石大道上，东南边隐约可见到扬州城的城墙。
LONG
	);
	set("outdoors", "sanbuguan");

	set("exits", ([
		"west" : "/d/sanbuguan/road4",
		"southeast" : "/d/sanbuguan/road2",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

