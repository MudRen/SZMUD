//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","驿站");
	set("long",@LONG
这是长安驿站，负责传送和京城里的往来公文。因为暂时还不开放给百姓
使用，所以没什么可参观的。
LONG
	);
	set("exits",([

                "west" : __DIR__"nroad3",
	]));

	setup();
}
