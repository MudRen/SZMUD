//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","长安东大街");
	set("long",@LONG
这里是长安城的人寻欢的好地方。街上的行人正悠闲地走着，路上偶尔传
来几声叫骂声，几个浓妆艳抹的女子正在街头买胭脂。一看就知道是南面的青
楼女子，几个浪荡男子正向红花阁走去。北面是城里有名的金玉楼，众多当地
的官绅都来此饮酒作乐。
LONG
	);
	set("exits",([
		"east" : __DIR__"dongmen",
		"west" : __DIR__"eroad2",
		"south" : __DIR__"honghuage",
		"northwest" : __DIR__"jinyulou",
		"north" : "/p/fystreet/street0",
	]));
	set("outdoors", "changan");
	setup();
}
