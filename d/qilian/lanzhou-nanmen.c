// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
���������ϳ��ţ�һ���޼ʵĴ��ԭ�����￪ʼ��
LONG
        );
        set("exits", ([
                "south" : __DIR__"prairie",
                "north" : __DIR__"lanzhou",
        ]));


	set("cost", 1);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
