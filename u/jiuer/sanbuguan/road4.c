//Cracked by shenzhou
// road4.c

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
你走在一条青石大道上，四周静悄悄的。
LONG
	);
	set("outdoors", "sanbuguan");

	set("exits", ([
		"west" : "/d/sanbuguan/road5",
		"east" : "/d/sanbuguan/road3",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

