// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
̧����ȥ����ããһƬɳĮ�����޾�ͷ, ֱ����ߣ�����ɳ���ʳ���
�������в�ˮ�������Կɼ�Щ��ݻ�ɳ�ݡ�������פ��ʱ�����˴��ɳ
�á�ɳ��ʲô�ġ�
LONG
        );
        set("exits", ([
                "north" : __DIR__"gebi4.c",
                "south" : __DIR__"gebi3.c",
		"east" :__DIR__"xiala1",
		"west" :__DIR__"gebi2.c",
        ]));


	set("cost", 4);
	set("outdoors","qilian-shan");
        setup();
	replace_program(ROOM);
}

