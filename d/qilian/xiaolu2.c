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
                "west" : __DIR__"xiaolu",
                "north" : __DIR__"xiaolu3",
                "east" : __FILE__,
		"south" :__DIR__"xiaolu",
        ]));


	set("cost", 1);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
