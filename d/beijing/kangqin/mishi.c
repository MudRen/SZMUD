//Cracked by Roath
// Room: /d/beijing/kangqin/mishi.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"fotang",
  "east" : __DIR__"mishi2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
