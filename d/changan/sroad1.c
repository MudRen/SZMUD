//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","长安南大街");
	set("long",@LONG
你走在一条大石板街上，萧萧秋风扫过此处，发黄的叶子凋落下来。边上
的店家正举头遥望大街上。在这就能听到一些小孩的朗朗读书声了。
LONG
	);
	set("exits",([
		"northeast" : __DIR__"wwroad4",
		"northwest" : __DIR__"wwroad3",
		"south" : __DIR__"sroad2",
	]));
set("outdoors", "changan");
	setup();
}
