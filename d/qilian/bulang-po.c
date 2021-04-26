// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����������ɽ���Ŀ�ʼ�����Ƹ��ӡ�ɽ�ж�Ϊ�˼�����֮��������ķᣬ
��ɽ�����ڶ�Ұ�������Ѳ�ԡ��ñ��ĺ�ȥ����
LONG
        );
        set("exits", ([
                "south" : __DIR__"bonan-shan",
                "north" : __DIR__"bulang-po2",
        ]));

	set("objects", ([
		"/d/forest/npc/mulang" : 1,
	]));

	set("cost", 3);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
