//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","长安西大街");
	set("long",@LONG
你走在一条宽阔的石板大街上，东面就快到城中心了。北面是条大道，不
知道通向何处，一些官家小姐匆匆忙忙向大道那边走去，几个卖冰糖葫芦的人
也跑上前去，想从这些阔小姐手里多得一些银两。
LONG
	);
	set("exits",([
                "east" : __DIR__"wroad3",
		"west" : __DIR__"ximen",
		"north" : __DIR__"byxiang",
	]));
set("outdoors", "changan");
	setup();
}
