//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","打铁铺");
	set("long",@LONG
一走进这个屋子，你就满身开始冒热汗。屋子的角落边放着一个正在吐着
火苗的炉子。一个打铁匠正挥动手中的锤子在锻造武器。边上的架子上摆放着
几样兵器。
LONG
	);
	set("exits",([

		"west" : __DIR__"sroad6",
	]));

	setup();
}
