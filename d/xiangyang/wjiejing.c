// Code of ShenZhou
// Room: /d/xiangyang/wjiejing.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : -15, "y" : -1 ]) );
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"qilidian",
]));

	setup();
	replace_program(ROOM);
}
