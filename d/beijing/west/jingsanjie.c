//Cracked by Roath
// Room: /d/beijing/west/jingsanjie.c

inherit ROOM;

void create()
{
	set("short", "��ɽ��");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"gulou",
  "east" : __DIR__"huoshenmiao",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
