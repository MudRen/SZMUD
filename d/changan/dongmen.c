//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","东华门");
	set("long",@LONG
东华门戒备森严，一些官兵正在检查过往进城的行人。不时有快马从外地
从这里急冲而过，那是送到知府衙门的公文。行人们每天到了这里都要都要耽
误一段时间。城门顶上写着[东华门]三个大字，苍劲而有力。
LONG
	);
	set("exits",([

		"west" : __DIR__"eroad3",
                "east" : "/d/village/sroad1",
		
	]));
	set("objects",([
                 __DIR__"npc/wujiang2":1,
                 __DIR__"npc/bing":2,
        ]));


         set("outdoors", "changan");
	setup();
}
