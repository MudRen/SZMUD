//Cracked by Roath
// Room: /d/beijing/kangqin/moongate.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"zhoulang7",
  "east" : __DIR__"garden2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
