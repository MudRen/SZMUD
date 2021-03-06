// Code of ShenZhou
// Room: /d/dali/yuxuguan1.c

inherit ROOM;

void create()
{
	set("short", "玉虚观前");
	set("long", @LONG
东面一座庙观，门前匾上写着“玉虚观”三个大字，西边一个
碧水荡漾的小湖，四周绿柳成荫，实乃修心养性的好地方。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	set("cost", 2);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/daogu" : 2,
]));
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yuxuguan2.c",
  "south" : __DIR__"quan2",
]));

	setup();
	replace_program(ROOM);
}
