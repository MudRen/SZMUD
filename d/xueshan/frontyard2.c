// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "ǰƫԺ");
        set("long", @LONG
������ѩɽ��ǰƫԺ�����ڽ����������������Խ��Խ�࣬����ҲԽ��
Խ�࣬���Ա���ǰԺ��������֮���ƫԺ�´���������̳�������С���ﾭ
�������������¡�
LONG
        );
        set("exits", ([
                "east" : __DIR__"frontyard",
                "north" : __DIR__"frontyard3",
                "west" : __DIR__"putita",
        ]));

        set("objects", ([
                __DIR__"npc/fsgelun" : 1,
                __DIR__"obj/jitan2" : 1,
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
