// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
̧����ȥ����ããһƬɳĮ�����޾�ͷ, ֱ����ߣ�����ɳ���ʳ���
�������в�ˮ�������Կɼ�Щ��ݻ�ɳ�ݡ�
LONG
        );
        set("exits", ([
                "east" : __DIR__"shamo2",
                "south" : __DIR__"xiala4",
		"north" :__DIR__"xiala1",
		"west" :__DIR__"xiala1",
        ]));


	set("cost", 5);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
