// Code of ShenZhou
// Room: /d/dali/wangfuroad2.c

inherit ROOM;

void create()
{
	set("short", "甬路");
	set("long", @LONG
只见两边翠竹夹路，土地下苍苔布满，中间羊肠一条石子砌
的甬路。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yahuan" : 1,
]));
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"wangfuroad1",
  "north" : __DIR__"wangfu9",
]));
set("wangfu", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
