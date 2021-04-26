// Code of ShenZhou
// Room: /city/dayuan.c
// YZC 1996/11/13 

inherit ROOM;

void create()
{
	set("short", "大院子");
	set("long", @LONG
这里是一块用篱笆围成的大院子，院子中随意地种着稀稀落落的几棵桃树，树
树结着不大不小几个有青有红的桃子，这里安静得可以体会到甜蜜的香气味，远处
传来的鸟叫声显得格外清脆，和扬州繁华的城里形成了一个鲜明的对比。院子里便
是猪猪工作的地方，向东远眺是一片绿绿的田地。
LONG
	);

	set("exits", ([
                 "yz" : "/shenzhou/d/city/kedian.c",
	]));

	set("objects", ([
	]));

	set("cost", 0);
	setup();
	replace_program(ROOM);
}

