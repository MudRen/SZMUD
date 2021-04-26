// Room: /d/chengdu/chenggenlu1.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "城跟路");
	set("long", @LONG
这是靠近成都北门城墙跟的一条小路。东边折向东南，西边是提督府。
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
		"east" : __DIR__"chenggenlu2",
		"west" : __DIR__"tidugate",
	]));

	setup();
	replace_program(ROOM);
}

