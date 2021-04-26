// Room: tulu2.c 土路
// By xuanyuan

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条尘土飞扬的小路，因为四川自古就是富庶之地，所以放眼望去，
四周的田垅里郁郁青青。
LONG);
        set("outdoors", "chengdu");
        set("cost", 1);
	set("exits", ([
		"eastdown" : __DIR__"tulu3",
		"westup" : __DIR__"chuanxi1",
	]));

	setup(); 
	replace_program(ROOM);
}
