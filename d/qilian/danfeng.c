// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "����ƺ");
        set("long", @LONG
��ǰ��Ȼ������������¹Ϸˮ����Ϫ֮�ϣ�����ɽ����������Ŀ��
������һʯ�����ݴ����л˷��ڴˣ���ɽ�ɶ����������£�����һ����
ͨ��Ѫ�죬�������أ����Ե�����
LONG
        );
        set("exits", ([
                "enter" : __DIR__"mine",
                "north" : __DIR__"xiaolu8",
        ]));
	set("objects", ([
                "/kungfu/class/xueshan/darba" : 1,
        ]));


	set("cost", 1);
        setup();
        set("outdoors","qilian-shan");
      //  replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
        if (dir =="enter" ) {
            if (present("darba", environment(me)))
                return notify_fail("�����һ���ӵ�ס�㣬���һ����������Ҳ�ҿ�̽�ҵı��\n");
	return 1;
	}
	return ::valid_leave(me, dir);
        set("no_clean_up", 0);
}
