// Code of ShenZhou
// Room: /d/xiangyang/liangcang.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"jicang",
]));

	setup();
	replace_program(ROOM);
}
