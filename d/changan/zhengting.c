//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","正厅");
	set("long",@LONG
这里就是知府大人为民主持公道的地方，每天知府大人都要在这里办公、
给人感觉一种威严，做了错事的人在这里是坚持不了多长时间的。厅的正前方
悬着一块匾，上边写着「明镜高悬」。
LONG
	);
	set("exits",([
		"east" : __DIR__"qianyuan",
	]));

	setup();
}
