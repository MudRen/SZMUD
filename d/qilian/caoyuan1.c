// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "�ɹŴ��ԭ");
        set("long", @LONG
ͻȻһ�����µĲݷ�����ӭ�洵��������߳��˸�赣�����������ǰ
����һƬһ���޼ʵĴ��ԭ��
LONG
        );
        set("exits", ([
                "north" : __DIR__"caoyuan2",
                "south" : __DIR__"shamo2",
		"west" :__DIR__"caoyuan3",
        ]));


	set("cost", 3);
	set("resource/grass", 1);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
