//Cracked by Roath
// Room: /d/beijing/kangqin/zhoulang2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zhoulang4",
  "east" : __DIR__"dating",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
