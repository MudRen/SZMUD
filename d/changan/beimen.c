//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","北安门");
	set("long",@LONG
北安门戒备森严，一些官兵正在检查过往进城的行人。不时有快马从外地向这
里急冲而过，那是送到知府衙门的公文。行人们每天到了这里都要都要耽误一段时
间。城门顶上写着[北安门]三个大字，苍劲而有力。
LONG
	);
	set("exits",([

		"south" : __DIR__"nroad3",
                "north" : "/d/huanghe/huanghe",
	]));
	set("objects",([
                 __DIR__"npc/wujiang2":1,
                 __DIR__"npc/bing":2,
]));
       

	set("outdoors", "changan");
	setup();
}
