// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "���볡");
        set("long", @LONG
������ѩɽ�ļ��볡�����ڽ����������������Խ��Խ�࣬����ҲԽ��
Խ�࣬����ѩɽ�¾��˽���ר�ż����õĹ㳡�������¼���������̳����ʹ
���������Ȼ�Եúܿտ�������������һ�����µ����ա�
LONG
        );
        set("exits", ([
                "east" : __DIR__"jisichang1.c",

        ]));

        set("objects", ([
                __DIR__"npc/fsgelun" : 1,
                __DIR__"obj/jitan5" : 1,
        ]));

        set("cost", 1);
        setup();
        set("outdoors","qilian-shan");
}
int valid_leave(object me, string dir)
{
        object ob;
        ob=(present("fa tan", (environment(me))));
        if ( me->query("name") == ob->query("pending")
        && ob->query("burning"))
                return notify_fail("�㷨��û��������ߣ�\n");
        return ::valid_leave(me, dir);
}
