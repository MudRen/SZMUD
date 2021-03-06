// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "大草原");
        set("long", @LONG
西北平原上的大草原，较之蒙古草原毫不逊色。绿油油的牧草直连
天边。西北的蓝天绿地，比起东北的黑山白水来，别有一番风趣。
LONG
        );
        set("exits", ([
                "north" : __DIR__"lanzhou-nanmen",
		"south" :__FILE__,
		"west" :__DIR__"prairie2",
		"east" :__FILE__,
        ]));

	set("objects", ([
                "/d/xingxiu/npc/herdsman" : 1,
                __DIR__"npc/yang2" : 2,
// 由于找不到绵羊在游戏里出现，所以在这个地方添加一个。
        ]));


	set("resource/grass", 1);
	set("cost", 2);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
