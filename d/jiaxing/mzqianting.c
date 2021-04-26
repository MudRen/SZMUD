// Code of ShenZhou
// Jay 8/9/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "÷ׯǰ��");
        set("long", @LONG
������쾮������һ����÷��֦�����������ǲԾ���������������
һ������(zhongtang)���������(door)����һƬ÷�֡�
LONG
        );
        set("exits", ([
		"west" : __DIR__"jiushi",
		"east" : __DIR__"qishi",
		"north" : __DIR__"huilang",
		"south" : __DIR__"mzgate"
	]));

        set("item_desc", ([
		"door" : "�����ƺ���δ������\n", 
                "zhongtang" : "����������һ�����˵ı��棬ī�����죬�����۽���"
			"���⡸��������������ī�����֣��ʷ�ɭ�ϣ�һ�ʱ��糤"
			"���Ĵ̻���\n",
        ]));
        create_door("south","����","north", DOOR_CLOSED);
	set("objects", ([
		__DIR__"npc/dingjian" : 1,
		__DIR__"npc/shilingwei" : 1,
	]));
        set("no_clean_up", 0);

	set("cost", 1);
	setup();
        replace_program(ROOM);
}
