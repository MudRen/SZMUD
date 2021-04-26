// Code of ShenZhou
// Room: /d/dali/guandao6.c

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
这是一条蜿蜒崎岖的山间土路，是由中原通向大理的官道。此处
属川南，向西南去的盘山路通上云贵山区，继而可达南昭大理国，此
去向北不远就是蜀中名川--峨嵋山。
LONG
	);

	set("cost", 3);

	set("outdoors", "dali");

	set("exits", ([
		"northeast" : "/d/emei/shijie1",
		"southwest" : __DIR__"guandao5",
		]));

	set("no_clean_up", 0);
	setup();
}
