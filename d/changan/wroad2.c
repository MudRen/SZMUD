//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","长安西大街");
	set("long",@LONG
你走在一条宽阔的石板大街上，东面就快到城中心了，可以看到钟楼耸立于
前。北边是个只有穷人住的地方,往西就快要出城了。
LONG
	);
	set("exits",([
                "southwest" : __DIR__"chougou",
                "east" : __DIR__"wroad1",
                "west" : __DIR__"wroad3",
		"north" : __DIR__"dadao",
	]));
set("outdoors", "changan");
	setup();
}
