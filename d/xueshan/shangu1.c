// Code of ShenZhou
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "��ѩɽɽ��");
        set("long", @LONG
ɽ�����ػ�ѩ�����ܶ����ͱڡ�ֻ������һ�����ڣ������ƺ��и�ɽ����
LONG
        );
        set("exits", ([
                "northdown" : __DIR__"shangu",
                "east" : __DIR__"cave1",
        ]));
	set("objects", ([
                "/kungfu/class/xuedao/shengdi" : 1,
        ]));


	set("cost", 3);
	set("bing_can", 2);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
