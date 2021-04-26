// Code of ShenZhou
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "���䳡");
        set("long", @LONG
����ɮ��������ĵط��������м������������䡣�䳡������
���Ǿ��ú��о��ã���������̨���Ƕ�ĸ�����һ������ͨ���
��Ժ��
LONG
        );
        set("exits", ([
                "west" : __DIR__"jingtang",
		"east" : __DIR__"songjing",
		"south" : __DIR__"frontyard",
		"north" : __DIR__"zoulang",
		"northup" : __DIR__"dumudian",
        ]));

	set("objects", ([
		__DIR__"npc/gelun" : 2,
	]));
	set("cost", 1);
        setup();
	set("outdoors","qilian-shan");
        replace_program(ROOM);
}
