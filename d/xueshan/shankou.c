// Code of ShenZhou
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "��ѩɽ��");
        set("long", @LONG
�����Ѿ����˲رߣ���ѩɽ��ɽ�ڡ���ѩɽ�ֽ��ɽ��λ�ڴ�
��֮�䣬����ɽ�Ƹ߾���ɽ�������겻���Ļ�ѩ���ʶ�����������
�����˼���ֻ�м�ֻͺӥ�ڸߴ�������������ããѩɽ��
LONG
        );
        set("exits", ([
                "eastdown" : __DIR__"shanlu7",
		"westup" : __DIR__"xshan",
        ]));
	set("objects", ([
                __DIR__"npc/tuying": 2,
        ]));

	set("cost", 2);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
