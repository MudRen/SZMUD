// Code of ShenZhou
// Room: /d/newdali/taihejie2.c

inherit ROOM;

void create()
{
	set("short", "中心广场");
	set("long", @LONG
这里就是阳苜咩城的中心，彩色石块铺成的大道向四方伸延。广
场呈菱形，一圈围的都是小贩，艺人，和看热闹的。熙熙攘攘的人群
中也少不了几个跑江湖之人，一些在中原闻所未闻的事物令一些刚入
江湖之人兴奋不已。往西便是著名的大理棋苑。
LONG
	);

	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([
		"south" : __DIR__"crossing.c",
		"north" : __DIR__"taihejie4.c",
		"east" : __DIR__"jiulou",
		"west" : __DIR__"qiyuan1.c",
		]));

	set("objects", ([
		__DIR__"npc/yiren" : 1,
		]));

	set("no_clean_up", 0);

	setup();
}
