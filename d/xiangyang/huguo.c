// Code of ShenZhou
// Room: /d/xiangyang/huguo.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
        set("coordinates", ([ "x" : 0, "y" : -9 ]) );
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"nanjie2",
]));

	setup();
	replace_program(ROOM);
}
