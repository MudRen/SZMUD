//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","长安西大街");
	set("long",@LONG
你走在一条宽阔的石板大街上，东面就快到城中心了，可以看到钟楼耸立
于前。
LONG
	);
	set("exits",([

		"west" : __DIR__"wroad2",
		"northeast" : __DIR__"xfroad1",
		"southeast" : __DIR__"wwroad1",
	]));
set("outdoors", "changan");
	setup();
}
