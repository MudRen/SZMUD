//Cracked by Roath
// Room: /d/beijing/kangqin/mishi2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"mishi",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
