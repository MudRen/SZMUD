//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","臭水沟");
	set("long",@LONG
这里奇臭无比，是居民倒垃圾的地方。到处都是绿头苍蝇在盘旋。边上有
些走不动的老乞丐常年蹲在这里。
LONG
	);
	set("exits",([
		"northeast" : __DIR__"wroad2",
	]));
	set("objects",([
                 "d/city/npc/qigai":1,
                 "d/city/npc/dog":1,
                 "d/city/npc/liumang":1,
        ]));
set("outdoors", "changan");
	setup();
}
