// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "��С·");
        set("long", @LONG
��ǰ��һ��һ����С·���ش�Խ��ԽƫƧ��·��Խ��Խ���ء�
LONG
        );
        set("exits", ([
                "east" : __DIR__"xiaolu"+(random(2)+4),
                "north" : __DIR__"xiaolu"+(random(2)+4),
                "west" : __DIR__"xiaolu"+(random(2)+4),
		"south" :__DIR__"xiaolu2",
        ]));


	set("cost", 1);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
