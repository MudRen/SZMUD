//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","西洪门");
	set("long",@LONG
西洪门戒备森严，一些官兵正在检查过往进城的行人。不时有快马从外地向这
里急冲而过。城门顶上写着[西洪门]三个大字，苍劲而有力。
LONG
	);
	set("exits",([
		"east" : __DIR__"wroad4",
                "west" : "/d/xueshan/shanlu6",
	]));
	set("objects",([
                 __DIR__"npc/wujiang2":1,
                 __DIR__"npc/bing":2,
        ]));
set("outdoors", "changan");
	setup();
}
