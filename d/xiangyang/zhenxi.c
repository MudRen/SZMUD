// Code of ShenZhou
// Room: /d/xiangyang/zhenxi.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
        set("coordinates", ([ "x" : -6, "y" : -0 ]) );
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"xijie2",
  "west" : __DIR__"tulu1",
]));

	setup();
	replace_program(ROOM);
}
