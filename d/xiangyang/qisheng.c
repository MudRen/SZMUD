// Code of ShenZhou
// Room: /d/xiangyang/qishengmen.c

inherit ROOM;

void create()
{
	set("short", "��ʤ��");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
        set("coordinates", ([ "x" : 0, "y" : 6 ]) );
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"beijie3",
  "north" : __DIR__"tulu4",
]));

	setup();
	replace_program(ROOM);
}
