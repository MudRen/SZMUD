//Cracked by Roath
// Room: /d/beijing/east/xiaojin1.c

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northup" : __DIR__"jifangting",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
