// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
�������������ţ���������ʮ��Ĺٵ������³ǡ�
LONG
        );
        set("exits", ([
                "east" : __DIR__"weststreet",
                "west" : __DIR__"guandao1.c",
        ]));


	set("cost", 1);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
