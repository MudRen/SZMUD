// Code of ShenZhou
// Room: /d/dali/shufang.c

inherit ROOM;

void create()
{
	set("short", "书房");
	set("long", @LONG
这里是段王府的书房，大理国人人拜佛，这书房里就有佛经。
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 2 */
  "d/shaolin/obj/fojing21" : 1,
  "d/shaolin/obj/fojing11" : 1,
]));
	set("cost", 1);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"wangfu9",
]));

	setup();
	replace_program(ROOM);
}
