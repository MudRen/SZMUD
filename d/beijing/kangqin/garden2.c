//Cracked by Roath
// Room: /d/beijing/kangqin/garden2.c

inherit ROOM;

void create()
{
	set("short", "С��԰");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"woshi",
  "west" : __DIR__"moongate",
  "east" : __DIR__"fotang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
