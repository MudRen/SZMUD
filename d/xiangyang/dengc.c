// Code of ShenZhou
// Room: /d/xiangyang/dengcheng.c

inherit ROOM;

void create()
{
	set("short", "�˳�");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : -2, "y" : 12 ]) );
	set("exits", ([ /* sizeof() == 1 */
  "eastup" : __DIR__"aozhan",
]));

	setup();
	replace_program(ROOM);
}
