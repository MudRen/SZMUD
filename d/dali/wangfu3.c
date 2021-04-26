// Code of ShenZhou
// Room: /d/dali/wangfu3.c

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
这是一条青石板路，两边种了不少柏树，显得庄严肃穆。西
面是个花园，一阵阵浓郁的花香扑鼻而来。
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"wangfu4.c",
  "south" : __DIR__"wangfu2.c",
  "west" : __DIR__"wangfu6.c",
  "east" : __DIR__"wangfu5.c",
]));
	set("no_clean_up", 0);

set("wangfu", 1);
	setup();
	replace_program(ROOM);
}
