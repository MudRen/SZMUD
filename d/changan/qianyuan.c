//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","前院");
	set("long",@LONG
过了前院就到了衙门正厅了。院子边上摆了些兵器，旁边还有些沙袋，那
是今年上任的知府大人新下的规矩，每个衙役都要练好身子骨。几个瘦弱的衙
役正在打沙袋。
LONG
	);
	set("exits",([

		"west" : __DIR__"zhengting",
		"southeast" : __DIR__"gfdoor",
	]));

	setup();
}
