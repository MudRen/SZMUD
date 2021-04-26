// Code of ShenZhou
// AceP

inherit ROOM;

void create()
{
	set("short", "客厅");
	set("long", @LONG
万劫谷的正房，这是一间大客厅，宽敞明亮，青石铺的地，两边
靠墙摆着的刀枪架，十八般兵器样样俱全。正中一张八仙桌，上有清
茶一盏。旁边是谷主坐的太师椅。
LONG
	);

	set("exits", ([
		"south" : __DIR__"wjg2.c",
		"east"  : __DIR__"wjg5.c",
	]));

	set("objects", ([
		__DIR__"npc/zhongwanchou": 1,
	]));

	set("cost", 1);
	setup();
}
