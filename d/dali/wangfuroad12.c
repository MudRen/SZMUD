// Code of ShenZhou
//zyz /12/13/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "�·");
        set("long", @LONG
ֻ�����ߴ����·�������²�̦�������м���һ��ʯ����
���·��
LONG
        );


set("wangfu", 1);
        set("outdoors", "dali");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

