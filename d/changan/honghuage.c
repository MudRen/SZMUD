//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","红花阁");
	set("long",@LONG
这里是一些无家可归，而又无所依靠的女子出卖自己身体的地方，其实就
是青楼，红花阁最初是个收养贫穷女子的地方，后不知怎得，变成风尘女子出
卖色相的场所。几个女子正满脸笑意的向一个富家公子敬酒，公子爷长的肥头
猪耳，令人一阵呕吐。
LONG
	);
	set("exits",([

		"north" : __DIR__"eroad3",
	]));

     set("objects", ([
          __DIR__"npc/guinu" : 1,
     ]));
	setup();
}
