//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","墨守居");
	set("long",@LONG
这里是附近的小孩读书的地方，这里的先生是有名的秀才，所以来这里读
书的小孩特别多，不乏有些老童生。在这里不时可以看到三三两两的人在争辩
着什么问题，还有一些来着请教的老先生从这匆匆而过，似乎在思考一些问题。
LONG
	);
	set("exits",([

		"west" : __DIR__"sroad2",
	]));
     set("objects",([
     "/d/city/npc/xiucai" : 1,
     ]));

     set("cost", 0);


	setup();
}
