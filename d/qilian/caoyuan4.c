// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "�ɹŴ��ԭ");
        set("long", @LONG
һ���޼ʵĴ��ԭ�ϣ���Ⱥ��ţ��ǰ����һ�����һ���ɹŰ�����������
Ȼ�����ʮ���������ӳ������Ĵ����
LONG
        );
        set("exits", ([
                "south" : __DIR__"caoyuan3",
		"west" :__DIR__"caoyuan3",
		"east" :__DIR__"caoyuan3",
		"enter" :__DIR__"bao",
        ]));
	set("objects", ([
                "/d/qilian/npc/meng-shi1.c" : 4,
        ]));

	set("cost", 3);
        setup();
	set("resource/grass", 1);
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
