//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","兵营大门");
	set("long",@LONG
这里就是长安城的兵营大门了，官兵把着门，你想往你看，被兵将给堵住了，
在这里，连一只蚂蚁也难想进去，里面关着重要的犯人。因此，守卫这里的官兵
不感有半点松懈。
LONG
	);
	set("exits",([
                "east" : __DIR__"sroad3",
		"west" : __DIR__"bingying",
	]));
        set("no_fight",1);
	set("objects",([
               
                 __DIR__"npc/bing":2,
        ]));

	setup();
}
