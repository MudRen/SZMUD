// Code of ShenZhou
// xuetang.c ѧ��
// qfy Nov 7, 1996.

#include "room.h"

inherit ROOM;

void create()
{
        set("short", "ѧ��");
        set("long", @LONG
���ǳ����һ��ѧ�ã����е��ӵܱ��ڴ��ϿΡ�ѧ����Ĺ������������
��������������������Ȫ�ݵ�ŷ��ղ������
LONG
        );

        set("exits", ([
                "east" : __DIR__"gtxiang",
        ]));

	set("objects",([
                __DIR__"npc/ouyang" : 1,
        ]));

	set("cost", 1);
        setup();
}

int valid_leave(object me, string dir)
{
        me->set_temp("mark/��", 0);
        return 1;
}
