//Cracked by Roath
// Room: /d/beijing/kangqin/woshi.c

inherit ROOM;

void create()
{
	set("short", "��ү����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"neishi",
  "north" : __DIR__"garden2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
