//Cracked by Roath
// Room: /d/beijing/west/puandian.c

inherit ROOM;

void create()
{
	set("short", "�հ���");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"yongansi",
  "north" : __DIR__"baita",
  "east" : __DIR__"zhizhudian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
