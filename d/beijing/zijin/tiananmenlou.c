//Cracked by Roath
// Room: /d/beijing/taihe/tiananmenlou.c

inherit ROOM;

void create()
{
	set("short", "�շ���");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"tiananmen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
