// Code of ShenZhou
// Room: /d/xiangyang/zyfen.c

inherit ROOM;

void create()
{
	set("short", "״Ԫ��");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 3, "y" : 12 ]) );
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"fancheng",
]));

	setup();
	replace_program(ROOM);
}
