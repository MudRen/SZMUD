//Cracked by Roath
// Room: /d/beijing/kangqin/houtang.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"tianjing",
  "west" : __DIR__"zhoulang8",
  "south" : __DIR__"garden",
  "east" : __DIR__"zhoulang7",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
