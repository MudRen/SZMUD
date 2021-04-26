// Code of ShenZhou
// AceP

inherit ROOM;

void create()
{
	set("short", "绿玉溪沿岸");
	set("long", @LONG
一条颇宽敞的土路沿着绿玉溪南岸横贯东西，一边是涓涓溪流碧
波荡漾，另一边是青山翠柳，郁郁葱葱的林木。东面有桥渡溪通向大
理城南门，西去不远就是五华楼了。
LONG
	);

	set("exits", ([
		"west" : __DIR__"shanlu7.c",
		"east" : __DIR__"shqiao.c",
		]));

	set("cost", 2);
        set("fjing", 1);
	set("outdoors", "dali");
	setup();
}
