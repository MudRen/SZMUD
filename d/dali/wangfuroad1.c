// Code of ShenZhou
// Room: /d/dali/wangfuroad1.c

inherit ROOM;

void create()
{
	set("short", "甬路");
	set("long", @LONG
只见两边翠竹夹路，土地下苍苔布满，中间羊肠一条石子砌
的甬路。
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"wangfu4.c",
  "east" : __DIR__"wangfuroad2.c",
]));
	set("no_clean_up", 0);
set("wangfu", 1);

	setup();
	replace_program(ROOM);
}
