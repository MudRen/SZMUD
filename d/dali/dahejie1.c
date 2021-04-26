// Code of ShenZhou
// Room: /d/newdali/dahejie1.c

inherit ROOM;

void create()
{
	set("short", "大和街");
	set("long", @LONG
大道旁店铺林立，长街故朴，屋舍鳞次栉比，道上人来车往，一片太
平热闹景象。路口种了俩颗大菩提树，一踏入巷中，阵阵茶花香气扑鼻而
来。
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"baiyishuguan.c",
  "south" : __DIR__"baiyiminju",
  "west" : __DIR__"crossing.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}









