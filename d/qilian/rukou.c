// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
�����ܵĹ��߶�ʱ������������ǰ��һ��ʯ�ڣ�ʯ����������
�Ѻ�����ȼ���š�
LONG
        );
        set("exits", ([
                "enter" : __DIR__"rukou1",
		"out" : __DIR__"qitian",
        ]));
//	set("objects", ([
 //               "/d/qilian/npc/tan-shi1" : 4,
//        ]));


	set("cost", 2);
        setup();
}
int valid_leave(object me, string dir)
{

        if (dir =="enter" && me->query("xjjt")<1 && me->query("xjjz")<1) { 
            if (present("wei shi", environment(me)))
                return notify_fail("������ʿ��ס���ȥ·�����·Ǳ���������ذɣ�\n");

        return 1;
}

        return ::valid_leave(me, dir);
        set("no_clean_up", 0);
}
