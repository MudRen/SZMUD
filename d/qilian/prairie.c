// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "���ԭ");
        set("long", @LONG
����ƽԭ�ϵĴ��ԭ����֮�ɹŲ�ԭ����ѷɫ�������͵�����ֱ��
��ߡ������������̵أ����𶫱��ĺ�ɽ��ˮ��������һ����Ȥ��
LONG
        );
        set("exits", ([
                "north" : __DIR__"lanzhou-nanmen",
		"south" :__FILE__,
		"west" :__DIR__"prairie2",
		"east" :__FILE__,
        ]));

	set("objects", ([
                "/d/xingxiu/npc/herdsman" : 1,
                __DIR__"npc/yang2" : 2,
// �����Ҳ�����������Ϸ����֣�����������ط����һ����
        ]));


	set("resource/grass", 1);
	set("cost", 2);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
