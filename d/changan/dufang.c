//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","赌坊");
	set("long",@LONG
这里是赌场的大堂，四周的房间里传出来吆五喝六的赌博声。
几个赌鬼正在赌桌上玩的尽兴呢。
LONG
	);
	set("exits",([
		"east" : __DIR__"wwroad2",
	]));

	setup();
}
