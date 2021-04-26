// Code of ShenZhou
// Room: /d/dali/taihejie6.c

inherit ROOM;

void create()
{
	set("short", "太和街口");
	set("long", @LONG
这条街由南门直通皇宫大门，是大理城内的主要街道。通街
全用天然的大块青石铺成。街上行人络绎不绝。街道西面可以看
到一面巨形石碑。        
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"taihejie5.c",
  "west" : __DIR__"shibei.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
