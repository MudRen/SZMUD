//Cracked by Roath
// Room: /d/beijing/west/hubianxiaodao6.c

inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"nanhainanan",
  "north" : __DIR__"nanhaidongan",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
