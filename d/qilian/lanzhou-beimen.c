// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "���ݱ���");
        set("long", @LONG
������������һ������ݵı��š��������򶫱���������ſɵ�
��ԭ��
LONG
        );
        set("exits", ([
                "south" : __DIR__"lanzhou",
                "northeast" : __DIR__"xiaojiaqiao",
        ]));


	set("cost", 1);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
