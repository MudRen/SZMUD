// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "��ʯ�ٵ�");
        set("long", @LONG
������һ����ʯ�ٵ��ϣ����������ǳ���æ����ʱ������������ҴҶ�����
���������һЩС��̯���ƺ���һ�����С�����ͨ���³ǡ�
LONG
        );
        set("exits", ([
                "west" : __DIR__"guandao2",
                "east" : __DIR__"lanzhou-ximen",
        ]));


	set("cost", 1);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
