//Cracked by Roath
// Room: /d/beijing/zijincheng/taijidian.c

inherit ROOM;

void create()
{
	set("short", "̫����");
	set("long", @LONG
�����������������Ǿ�ס�ĵط�.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"tiyuandian",
  "east" : __DIR__"yongshougong",
]));
	set("no_clean_up", 0);
	set("exit", "e");

	setup();
	replace_program(ROOM);
}
