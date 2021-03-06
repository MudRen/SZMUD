// Code of ShenZhou
// xuetang.c 学堂

#include "room.h"

inherit ROOM;

void create()
{
        set("short", "桃花学馆");
        set("long", @LONG
教书先生曾是黄岛主的家仆。前两年母亲亡故，离岛奔丧刚刚回来。黄药师念
他一片诚心而年纪又大了，便让他在桃花岛上开馆教书。桃花弟子终于也可在
桃花岛上学些文化。
LONG
        );

        set("exits", ([
                "east" : __DIR__"bibochi",
        ]));

	set("objects",([
                __DIR__"npc/xueshi" : 1,
        ]));

	set("cost", 1);
        setup();
}

int valid_leave(object me, string dir)
{
        me->set_temp("mark/朱", 0);
        return 1;
}
