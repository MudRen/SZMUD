// Code of ShenZhou
// Room: /d/dali/taihejie.c

inherit ROOM;

void create()
{
	set("short", "太和街口");
	set("long", @LONG
这条街由南门直通皇宫大门，是大理城内的主要街道。
通街全用天然的大块青石铺成。街上行人络绎不绝。        
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"taihejie1.c",
  "south" : __DIR__"southgate.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
