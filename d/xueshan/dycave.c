// Code of ShenZhou
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
�տյ���һ��ɽ������Ҳ����ɾ�����ͷ����һ��ʯ����
LONG
        );
        set("exits", ([
                "out" : __DIR__"shangu3",
        ]));
	set("objects", ([
                __DIR__"obj/yuyi": 1,
	]));

	set("sleep_room",1);
	set("cost", 1);
        setup();
	replace_program(ROOM);
}
