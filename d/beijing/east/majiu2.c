//Cracked by Roath
// Room: /d/beijing/east/majiu2.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"majiu1",
  "west" : __DIR__"majiu3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
