//Cracked by Roath
// Room: /d/beijing/kangqin/garden.c

inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"shiwu",
  "west" : __DIR__"chufang",
  "north" : __DIR__"houtang",
  "east" : __DIR__"wuqiku",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
