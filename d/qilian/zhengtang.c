// Code of ShenZhou
// Qfy July 26, 1999.
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ��װ�޻��������ã������������ͷ��ۻ�ĵط���ǽ
�ϴ������ɷ����д�š�Ψ�Ҷ��𡱣������ݺᣬ�����ġ�
LONG
        );
        set("exits", ([
                "east" : __DIR__"neiyuan",
        ]));

	set("objects", ([
            __DIR__"npc/yanglt" : 1,
        ]));

	set("cost", 1);
	setup();

	replace_program(ROOM);
}
