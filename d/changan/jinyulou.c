//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","金玉楼");
	set("long",@LONG
这就是长安城最有名的金玉楼了，听说这里有道名菜，叫[金玉满堂]，而
酒楼也是因为这道菜才改成现今名声鼎沸的金玉楼。这里生意兴隆，大都是一
些富绅、官府衙门的人来这里做客，也因此没有人敢打这家酒楼的主意。酒楼
开业至今，都是平安无事。
LONG
	);
	set("exits",([

		"southeast" : __DIR__"eroad3",
	]));
set("objects", ([
     __DIR__"npc/jin.c" : 1,
]));
	
	setup();
}
