// Code of ShenZhou
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "��ѩɽ");
        set("long", @LONG
����ѩ�أ�����̹ǡ���������������ˣ���Ȼ���ܲ�ס�ˡ�
LONG
        );
        set("exits", ([
                "northdown" : __DIR__"xshan",
		"westup" : __DIR__"xshan2",
        ]));

	set("cost", 5);
	set("bing_can", 3);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
