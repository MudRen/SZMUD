// Code of ShenZhou
// shandong3.c ɽ��
// qfy 96/6/30

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
����һ��Сɽ��������Ҿ�һӦ�㱸��
LONG
        );

	set("exits", ([
                "out" : __DIR__"yelin3",
        ]));

	set("objects", ([
		CLASS_D("huashan") + "/buping" : 1,
	]));

	set("cost", 2);
        setup();
}
