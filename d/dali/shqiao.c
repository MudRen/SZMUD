// Code of ShenZhou
// Room: /d/dali/southgate.c

inherit ROOM;


void create()
{
	set("short", "双鹤桥");
	set("long", @LONG
这是一个岔路口，北边是座青石拱桥名叫双鹤桥，此桥跨在绿玉
溪上，桥北即是大理城，由此南去是通往南方的喜州、龙口等城镇的
官道，东去的岔路通往广西，沿绿玉溪南岸西行可达五华楼。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	set("cost", 1);
        set("fjing", 1);
	
	set("exits", ([
		"north" : __DIR__"southgate.c",
		"south" : __DIR__"minov63",
		"southeast" : __DIR__"tulu4",
		"west" : __DIR__"shanlu8",
		]));

	setup();
}
