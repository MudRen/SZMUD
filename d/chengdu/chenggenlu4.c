// Room: /d/chengdu/chenggenlu4.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "城跟路");
	set("long", @LONG
这是靠近成都东门城墙跟的一条小路。南边不远处就是东大街。
LONG
	);
        set("outdoors", "chengdu");
        set("cost", 1);
	set("exits", ([
		"northwest" : __DIR__"chenggenlu3",
		"south" : __DIR__"chenggenlu5",
	]));

	setup();
	replace_program(ROOM);
}

