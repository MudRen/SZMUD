// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "�ƺ�");
        set("long", @LONG
�ƺӳ����ຣ��������֮�����ܵ�������ԭ���赲��ת���򶫱�
��ȥ��������������ԭ�Ĺ�������ɳ����������ˮɫ�λƣ��ͱ���Ϊ�ƺӡ�
LONG
        );
        set("exits", ([
		"northeast" : "/d/forest/huanghe1",
                "west" : __DIR__"huanghe2",
        ]));
	set("cost", 2);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
