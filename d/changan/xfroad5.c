//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","幸福大街");
	set("long",@LONG
街上有些落叶，一阵风吹来，让人不寒而栗。东面是个马厩，一些江湖人
士经常在那里买马。西南方就是长安城最繁华的地段了，一些游人快步往前走，
引得一阵沙土气息。路上车水马龙，来往人潮不断。
LONG
	);
	set("exits",([
		"east" : __DIR__"majiu",
		"southwest" : __DIR__"center",
                "southeast" : __DIR__"xfroad6",
		"northwest" : __DIR__"xfroad4",
	]));
set("outdoors", "changan");
set("fanhua", 3);
	setup();
}
