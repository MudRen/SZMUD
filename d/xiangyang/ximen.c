// Code of ShenZhou
// Room: /d/xiangyang/ximen.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
        set("coordinates", ([ "x" : -6, "y" : -7 ]) );
	set("no_clean_up", 0);
	set("srhot", "����");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"djtai",
  "west" : __DIR__"tulu2",
]));
	set("shoot", "����");

	setup();
	replace_program(ROOM);
}
