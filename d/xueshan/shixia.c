// Code of ShenZhou
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "ʯϿ��");
        set("long", @LONG
����һ��������Ͽ�ȣ������˼�������Ͽ��������һƬ���ԭ��
�������ɽ�ˡ�
LONG
        );
        set("exits", ([
                "west" : __DIR__"shanlu1",
                "east" :"/d/qilian/prairie2",
        ]));
	set("objects", ([
                "/kungfu/class/xuedao/shanyong": 1,
        ]));


	set("cost", 3);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
