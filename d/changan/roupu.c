//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","肉铺");
	set("long",@LONG
走进这里就闻到一股肉腥味，几个妇女正在挑拣猪肉，一个屠夫正拿着一
把杀猪的尖刀给客人们切肉，旁边的几个帮忙杀猪的伙计，正在按着一头猪。
LONG
	);
	set("exits",([
		"northwest" : __DIR__"wwroad5",
	]));
	setup();
}
