// road: /baituo/luanshi.c

inherit ROOM;

void create()
{
        set("short","乱石丛");

        set("long",@LONG
这里遍地布满了大大小小的山石，石隙中偶尔夹杂着些高矮不齐，青
黄不一的杂草，石缝里几只褐黄色蚂蚁正迅速地爬动着，
LONG);

		set("exits",([ 
			"east" : "/d/xingxiu/bthill",
		]));

		set("cost",2);
		set("outdoors", "baituo");
        setup();

        replace_program(ROOM);
}
