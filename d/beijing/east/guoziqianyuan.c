//Cracked by Roath
// Room: /d/beijing/east/guoziqianyuan.c

inherit ROOM;

void create()
{
	set("short", "ǰԺ");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"guozidating",
  "west" : __DIR__"guoxixiang",
  "south" : __DIR__"guozidamen",
  "east" : __DIR__"guodongxiang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
