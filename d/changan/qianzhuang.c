//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","钱庄");
	set("long",@LONG
这是一家老字号的钱庄，已有几百年的历史，在全国各地都有分店。它发
行的银票信誉非常好，通行全国。
LONG
	);
	set("exits",([
		"east" : __DIR__"nroad3",
	]));
        set("objects", ([ 
                __DIR__"npc/bankhuoji" : 1,
]));

	setup();
}
