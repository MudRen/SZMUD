//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","威武大路");
	set("long",@LONG
路上发出一阵肉腥味，街的东南面是个肉铺，个妇女挎着袋子正走向那里。
突然，几匹快马从这急奔而过，这些人身配兵器，脸上由于蒙着面罩而看不清，
行人连忙避开。
LONG
	);
	set("exits",([
		"northwest" : __DIR__"center",
		"southeast" : __DIR__"roupu",
		"southwest" : __DIR__"wwroad4",
		"northeast" : __DIR__"wwroad6",
	]));
set("outdoors", "changan");
	setup();
}
