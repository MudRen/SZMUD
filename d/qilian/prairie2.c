// Code of ShenZhou
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "���ԭ");
        set("long", @LONG
�㽥������������������µ�һ����Сɽ���������ߣ��ܿ�
���߳���ԭ�ˡ�
LONG
        );
        set("exits", ([
                "west" : "/d/xueshan/shixia",
                "east" : __DIR__"prairie",
        ]));
	set("objects", ([
                "/d/qilian/npc/boy": 2,
        ]));
	set("resource/grass", 1);
	set("cost", 2);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
