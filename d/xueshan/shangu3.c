// Code of ShenZhou
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "��ѩɽɽ��");
        set("long", @LONG
һ�����ɽ��, Ⱥɽ����, ɽ����ȫ�ǰ������Ļ�ѩ, ɽ���Ϸ�������ɽ����
LONG
        );
        set("exits", ([
                "enter" : __DIR__"dycave",
		"north" : __DIR__"wangyou",
        ]));


	set("cost", 3);
	set("bing_can", 2);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
