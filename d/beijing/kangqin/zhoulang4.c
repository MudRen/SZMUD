//Cracked by Roath
// Room: /d/beijing/kangqin/zhoulang4.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"zhoulang2",
  "east" : __DIR__"tianjing",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}