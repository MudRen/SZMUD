//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","乱坟堆");
	set("long",@LONG
这里都是一些不知姓名或者被官府斩首的人埋尸的地方，一阵荒凉，偶有
几个江湖人在这祭拜。
LONG
	);
	set("exits",([
		"northwest" : __DIR__"luansg",
          "westup" : __DIR__"dtt",
	]));
set("outdoors", "changan");
	setup();
}
