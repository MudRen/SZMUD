// Code of ShenZhou
// Room: /d/dali/wuhua1.c

inherit ROOM;

void create()
{
	set("short", "大厅");
	set("long", @LONG
这里是五华楼的前大厅，异常宽敞明亮，足有一里见方，全是云
石铺地，黑白相间，足足可以容纳二、三千人。时时可见锦衣侍者手
托美食来回行走。
LONG
	);
	set("exits", ([
		"out" : __DIR__"shanlu7.c",
		"north" : __DIR__"wuhua2.c",
		]));

	set("objects", ([
		__DIR__"npc/waiter" : 3,
        ]));

	set("no_clean_up", 0);
	set("cost", 1);
	setup();
}
