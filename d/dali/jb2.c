// Code of ShenZhou
// Room: /dali/jb2.c
// AceP

inherit ROOM;

void create()
{
	set("short", "善人渡");
	set("long", @LONG
这里是条小路。前面有座过江的铁索桥，桥旁石上刻有“善人渡”。过桥去，
就回到无量山区了。
LONG );

	set("exits", ([
		"back"   : __DIR__"jb1",
		"bridge" : __DIR__"wls17",
	]));

	set("cost", 2);
        set("outdoors", "dali");
	setup();
}
