// Code of ShenZhou
// Room: /d/dali/wangfua.c

inherit ROOM;

void create()
{
	set("short", "小院");
	set("long", @LONG
这是王府的仆人院。东西方各有一间厢房，那是仆人们的卧房。
南边是一间厨房。?
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiaosi" : 2,
	"kungfu/class/dali/guducheng" : 1,
]));
	set("cost", 1);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"foodroom",
  "west" : __DIR__"wofang1.c",
  "north" : __DIR__"wangfu2.c",
  "east" : __DIR__"wofang2.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
