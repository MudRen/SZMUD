// Code of ShenZhou
// Room: /d/dali/garden1.c

inherit ROOM;

void create()
{
	set("short", "茶花园入口");
	set("long", @LONG
在一堵青色的石墙后面，隐隐可以看到一排排的垂柳，青
石门前站了一个老花匠，鼻中闻到随风漂来的淡淡茶花香味，
心中不禁一阵清明。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"wangfu5.c",
  "enter" : __DIR__"garden2.c",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
