// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "��ʯɳ·");
        set("long", @LONG
������һ����Ƨ����ʯɳ·�ϣ���������һ����ΰ�Ĺذ�������ͨ
���Ȫ��
LONG
        );
        set("exits", ([
                "southwest" : __DIR__"shalu1",
                "northeast" : __DIR__"jiayuguan",
        ]));


	set("cost", 1);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
