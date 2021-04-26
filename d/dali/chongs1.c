// Code of ShenZhou
// Room: /d/dali/chongs1.c

inherit ROOM;

void create()
{
	set("short", "塔内");
	set("long", @LONG
这是千寻塔的内部，有井字形楼梯可供游人攀登。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"chongs2.c",
  "out" : __DIR__"chongs.c",
]));
	set("no_clean_up", 0);
	set("cost", 3);
		setup();
	replace_program(ROOM);
}
