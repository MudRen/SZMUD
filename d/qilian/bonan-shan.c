// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "����ɽ");
        set("long", @LONG
�����ߣ������ѽ����ز���ƽ̹�����������ת��ɽ������·���˾�
�ж��ˣ�ֻʣ������ƽ��ɽ·����������������ɽ��������ͨ���³ǹٵ���
LONG
        );
        set("exits", ([
                "south" : __DIR__"guandao3",
                "north" : __DIR__"bulang-po",
        ]));


	set("cost", 3);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
