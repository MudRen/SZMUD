// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "��ͨ��");
        set("long", @LONG
������Ǵ�ͨ�룬Ϊ����������ɽ���Ľ�Ҫ֮�����ɼ�ɽ��Ұ�ñ���
��䣬���Ŵ˵�ʢ����֥����������ý����ֽŲ��á�
LONG
        );
        set("exits", ([
                "southeast" : __DIR__"bulang-po2",
                "westup" : __DIR__"niaoju",
		"northeast" : __DIR__"zhuti",
        ]));


	set("cost", 3);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
