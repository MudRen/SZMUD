//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","威武大路");
	set("long",@LONG
走在这条大路上，不免让你想到东面的赌坊豪赌一番。几个赌客可能因为
输了钱，被几个彪形大汉给架了出来，正在这条街上拉扯着，而旁人却自走自
的，好象没有什么事发生一样。
LONG
	);
	set("exits",([
		"northeast" : __DIR__"center",
		"southeast" : __DIR__"wwroad3",
		"west" : __DIR__"dufang",
		"northwest" : __DIR__"wwroad1",
	]));
set("outdoors", "changan");
set("fanhua", 2);
	setup();
}
