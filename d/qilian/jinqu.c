// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "�շ���");
        set("long", @LONG
һ���յ����ķ��䣬��һ�������ơ�
LONG
        );
        set("exits", ([
                "east" : __DIR__"xingtang",
        ]));
//       set("objects", ([
 //               __DIR__"obj/xjjling" : 1,
//	]));

	set("cost", 0);
        setup();
        replace_program(ROOM);
}
