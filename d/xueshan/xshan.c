// Code of ShenZhou
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "��ѩɽ");
        set("long", @LONG
�����ر�ѩ������ǰ�װ�����һƬ���Ӷ����������ģ�������ʼ���١�
LONG
        );
        set("exits", ([
                "eastdown" : __DIR__"shankou",
		"southup" : __DIR__"xshan1",
        ]));


	set("cost", 3);
	set("bing_can", 3);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
