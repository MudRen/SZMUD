// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "��ʯ�ٵ�");
        set("long", @LONG
������һ����ʯ�ٵ��ϣ�����������ϡ�٣����ж�ʮ�������
����ɽ���ˡ�
LONG
        );
        set("exits", ([
                "south" : __DIR__"xincheng",
                "north" : __DIR__"bonan-shan",
        ]));


	set("cost", 1);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
