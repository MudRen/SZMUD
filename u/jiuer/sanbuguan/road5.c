//Cracked by shenzhou
// road5.c

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
		"west" : __DIR__"road6",
		"east" : __DIR__"road4",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

