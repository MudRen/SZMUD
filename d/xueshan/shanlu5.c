// Code of ShenZhou
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
����һ����᫵�ɽ·����ӵ�������Ͳ�������ȥ�ˡ�ɽ·�����Ӳݴ�
����·��ʼԽ��Խ���ߡ�
LONG
        );
        set("exits", ([
                "northdown" : __DIR__"shanlu4",
		"southup" : __DIR__"shanlu6",
        ]));
	set("objects", ([
                __DIR__"npc/tuying": 1,
        ]));


	set("cost", 3);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
