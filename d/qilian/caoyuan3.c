// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "�ɹŴ��ԭ");
        set("long", @LONG
һ���޼ʵĴ��ԭ�ϣ���Ⱥ��ţ��ϡϡ�����м����ɹŰ���
LONG
        );
        set("exits", ([
                "north" : __DIR__"caoyuan2",
                "south" : __DIR__"shamo2",
		"west" :__FILE__,
		"east" :__FILE__,
        ]));


	set("resource/grass", 1);	
	set("cost", 3);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
