//Cracked by Roath
// Room: /d/beijing/west/hubianxiaodao5.c

inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"nanhaixian",
  "east" : __DIR__"nanhainanan",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
