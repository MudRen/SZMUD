//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","长安北大街");
	set("long",@LONG
走在大石板街上，长安的北街比较冷清，路上的行人较少。寒风吹过，让人毛骨悚然。
一般佩带兵器人从西面的江湖帮派进进出出，东面是条小路，不过很少人会走那里。
LONG
	);
	set("exits",([
		"east" : __DIR__"xiaolu",
                "west" : __DIR__"qlbfd",
		"south" : __DIR__"nroad1",
		"north" : __DIR__"nroad3",
	]));
set("outdoors", "changan");
set("fanhua", 2);
	setup();
}
