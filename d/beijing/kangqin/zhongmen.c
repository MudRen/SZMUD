//Cracked by Roath
// Room: /d/beijing/kangqin/zhongmen.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"dating",
  "north" : __DIR__"tingyuan",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
