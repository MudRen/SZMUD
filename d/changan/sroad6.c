//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","长安南大街");
	set("long",@LONG
这里是长安南大街，萧萧秋风扫过此处。走到这里，不时可以听到打铁的
声音，这条街上的打铁铺是远近闻名，很多武林人士都来这里卖称手的兵器。
LONG
	);
	set("exits",([
		"east" : __DIR__"datiepu",
		"south" : __DIR__"nanmen",
                "north" : __DIR__"sroad3",
	]));
set("outdoors", "changan");
	setup();
}
