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
                "north" : __DIR__"gebi4",
                "south" : __DIR__"gebi3",
		"east" :__DIR__"gebi7",
		"west" :__DIR__"gebi2",
        ]));


	set("cost", 5);
	set("outdoors","qilian-shan");
        setup();
	replace_program(ROOM);
}

