// Code of ShenZhou
// Room: /d/murong/qing5
//arthurgu /1999.9

#include "room.h"
inherit ROOM;

void create()
{
	set("short", "天井");
	set("long", @LONG
    江南大户人家的房屋多为三进三重结构，第一进大多是门房及
仆人们生活居住的场所，第二进为会客议事的地方，第三进则是内
眷生活区，第三进之后一般还有后花院。
LONG
	);
	set("cost", 1);
	set("exits", ([ 
        "south" : __DIR__"qing4",
        "north" : __DIR__"qing6",
        "west" : __DIR__"sleep1",
        "east" : __DIR__"sleep2",
                      ]));

	set("no_clean_up", 0);
        set("outdoors", "murong");

        set("objects", ([
		"/d/murong/npc/shinu" : 3,
		]));

	setup();
	
}

int valid_leave(object me, string dir)
{
        if (dir=="west" || dir=="east") {
                if (dir=="west" && me->query("gender")=="男性")
                        return notify_fail("那是女子的厢房！\n");
                if (dir=="east" && me->query("gender")=="女性")
                        return notify_fail("那是男子的厢房！\n");
        }
        return ::valid_leave(me, dir);
}
