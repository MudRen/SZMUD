//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","擂台");
	set("long",@LONG
这就是当今天子为选拔武艺高强的武林人士专门设立的擂台，东面有个兵
器架，上来比武的人都不得佩带自己的兵器，都必须用到兵器架上领取自己合
适的兵器。在这里，你不用怕有人会出卑鄙的手段。
LONG
	);
	set("exits",([

		"north" : __DIR__"eroad2",
	]));
	
	setup();
}
