//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","长安西大街");
	set("long",@LONG
你走在一条宽阔的石板大街上，东面就快到城中心了，唏唏嚷嚷，热闹非
凡，不时有游人来来往往，北面的花店刚开张不久。几个卖花姑娘正从里面出
来，拿着花去大街上叫卖。
LONG
	);
	set("exits",([
		"east" : __DIR__"wroad2",
		"west" : __DIR__"wroad4",
		"north" : __DIR__"huadian",
	]));
set("outdoors", "changan");
	setup();
}
