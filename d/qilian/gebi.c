// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
̧����ȥ����ããһƬɳĮ�����޾�ͷ��ֱ����ߣ�����ɳ���ʳ���
�������в�ˮ�������Կɼ�Щ��ݻ�ɳ�ݡ�������פ��ʱ�����˴��ɳ
�á�ɳ��ʲô�ġ�
LONG
        );
        set("exits", ([
                "north" : __DIR__"gebi1",
                "south" : __DIR__"yongchang",
		"east" :__FILE__,
		"west" :__FILE__,
        ]));
	set("objects", ([
                "/d/xingxiu/npc/shachong" : 1,
        ]));


	set("cost", 4);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
