// Code of ShenZhou
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
ɽ�����ѩ��£�ɼ���ѩ�ѣ�����ʱ������ɨ����ѩ����
ǰ����ͱ�������ԼԼ��һ��ɽ����
LONG
        );
        set("exits", ([
                "west" : __DIR__"shangu1",
                "enter" : __DIR__"cave2",
        ]));
	set("objects", ([
                "/kungfu/class/xuedao/baoxiang": 1,
        ]));



	set("cost", 2);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
