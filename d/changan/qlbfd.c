//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","权力帮分舵");
	set("long",@LONG
厅的正中央摆放着一个大屏风，屏风上画着一幅猛虎下山图。边上还有些座位，正中坐
着一位中年男子。一些帮众正忙着帮助摆放东西，听说今天有位重要人物要来，帮众们四处
走动，不敢掉以轻心。
LONG
	);
	set("exits",([
		"east" : __DIR__"nroad2",
	]));

	setup();
}
