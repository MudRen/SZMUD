//Cracked by Roath
// Room: /d/beijing/east/shufang2.c

inherit ROOM;

void create()
{
	set("short", "�鷿");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"guozihouyuan",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
