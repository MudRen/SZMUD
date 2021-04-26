// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "�³�");
        set("long", @LONG
���������������³ǣ�������פ���Ķ���֮�����������࣬
�����ر�������Ѱ���ϰ����ǲ��ÿ����ġ�
LONG
        );
        set("exits", ([
                "east" : __DIR__"guandao2",
                "north" : __DIR__"guandao3",
                "south" : __DIR__"prairie",
        ]));
        set("objects", ([
		"/d/xingxiu/npc/bing" : 4,
	]));

	set("cost", 1);
    set("outdoors", "qilian-shan");
	setup();
        replace_program(ROOM); 
}
