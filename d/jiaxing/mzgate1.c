// Code of ShenZhou
// Jay 8/9/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "÷ׯ����");
        set("long", @LONG
����һ��Ƭ÷�֣�����һ����ʯ����������һ�����Ű�ǽ�Ĵ�ׯ
Ժ�⣬����������������(door)��д�š�÷ׯ���������֣��Ա�����
�������Ĺ��⡹���֡�
LONG
        );
        set("exits", ([
		"west" : __DIR__"changdi",
		"north" : __DIR__"mzqianting1"
	]));
	set("objects", ([
		__DIR__"npc/ren" : 1,
	]));

        set("item_desc", ([
                "door" : "�����ƺ���δ������\n",
        ]));
        create_door("north","����","south", DOOR_CLOSED);
        set("no_clean_up", 0);

	set("cost", 1);
	setup();
	set("outdoors","quanzhou");
        replace_program(ROOM);
}
