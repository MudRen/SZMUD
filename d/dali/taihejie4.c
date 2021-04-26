// Code of ShenZhou
// Room: /d/newdali/taihejie4.c

inherit ROOM;

void create()
{
	set("short", "太和街口");
	set("long", @LONG
这条街由南门直通皇宫大门，是大理城内的主要街道。通街全用
天然的大块青石铺成。街上行人络绎不绝。大道两边遍植松柏，满目
苍翠。
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([
		"south" : __DIR__"taihejie2.c",
		"north" : __DIR__"taihejie5.c",
		"east" : __DIR__"road8.c",
		"west" : __DIR__"shegu.c",
		]));
	set("no_clean_up", 0);

	setup();
}
