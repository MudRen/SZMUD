//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","长安北大街");
	set("long",@LONG
走在大石板街上，长安的北街比较冷清，路上的行人较少。寒风吹过，让
人毛骨悚然。一般佩带兵器人从北面的江湖帮派走来。
LONG
	);
	set("exits",([

		"southeast" : __DIR__"xfroad4",
		"southwest" : __DIR__"xfroad3",
		"north" : __DIR__"nroad2",
	]));
set("outdoors", "changan");
	setup();
}
