//Created by RoomEditer on 02-1-3
//by bravo
inherit ROOM;

void create()
{
	set("short","长安南大街");
	set("long",@LONG
你走在一条大石板街上，萧萧秋风扫过此处，发黄的叶子凋落下来。边上
的店家正举头遥望大街上，盼望着有哪位客人要临门。东面传来一阵阵的朗朗
读书声，一听就知道是一群小孩在认真背诗。
LONG
	);
	set("exits",([
		"east" : __DIR__"moshouju",
                "west" : __DIR__"wuguan",
		"south" : __DIR__"sroad3",
		"north" : __DIR__"sroad1",
	]));
set("outdoors", "changan");
	setup();
}
