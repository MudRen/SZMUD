// Room: /d/chengdu/chenggenlu5.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "城跟路");
	set("long", @LONG
这是靠近成都东门城墙跟的一条小路。北边折向西北，南边是东大街。
LONG
	);
        set("outdoors", "chengdu");
        set("cost", 1);
	set("exits", ([
		"north" : __DIR__"chenggenlu4",
		"south" : __DIR__"dadongmen",
	]));

	setup();
	replace_program(ROOM);
}

