// Code of ShenZhou
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "���±�Ժ");
        set("long", @LONG
���������»��͹��Ʋֹ�ʦ��ס����Ժ��С�����磬����������
���»��͹��Ʋֹ�ʦͨ������������ͽ��
LONG
        );
        set("exits", ([
                "north" : __DIR__"houyuan2",
        ]));
	set("objects", ([
                __DIR__"npc/lazhangfo" : 1,
        ]));

	set("cost", 1);
        setup();
        replace_program(ROOM);
}
