// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������������һ������վ�������ɹţ������ຣ���������ں�������
������ԭ��������һ��Ҫ���������ǹ����������������Źء�
LONG
        );
        set("exits", ([
                "southup" : __DIR__"tanglang",
                "southwest" : __DIR__"jiayuguan",
		"north" :__DIR__"halahu",
        ]));


	set("cost", 2);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
