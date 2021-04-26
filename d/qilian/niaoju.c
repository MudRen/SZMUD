// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "���̨");
        set("long", @LONG
���Ŵ�ͨ�������ߣ���·���Լ��ѡ���;������������ʯ���ף���
�������޼������ˣ�ȴ�а���Ⱥ�ɣ�����ֻ����֮������ͷ���죬һ
Ƭ����֮�£������������ԲԴ�أ����ڽ��£��������������
LONG
        );
        set("exits", ([
                "eastdown" : __DIR__"datong-ling",
                "northup" : __DIR__"mazong",
                "northwest" : __DIR__"qilian",
        ]));

	set("objects" , ([
		"/d/jiaxing/npc/wuya" : 1,
		"/d/city/npc/maque" : 2,
	]));

	set("cost", 2);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
