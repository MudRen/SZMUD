//Cracked by Roath
// Room: /d/beijing/kangqin/neishi.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"woshi",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
