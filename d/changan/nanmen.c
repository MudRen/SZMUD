//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","南安门");
	set("long",@LONG
南安门戒备森严，一些官兵正在检查过往进城的行人。因为南面的三不管
经常有些土匪路霸等来此打劫。行人们每天到了这里都要都要耽误一段时间。
城门顶上写着[南安门]三个大字，苍劲而有力。
LONG
	);
	set("exits",([

		"north" : __DIR__"sroad6",
                "south" : "/d/emei/emroad5",
	]));
	set("objects",([
                 __DIR__"npc/wujiang2":1, 
                 __DIR__"npc/bing":2,
        ]));
set("outdoors", "changan");
	setup();
}
