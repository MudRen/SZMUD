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
                "northeast" : __DIR__"xiaolu"+(random(3)+6),
                "northwest" : __DIR__"xiaolu9",
                "southeast" : __DIR__"xiaolu"+(random(3)+6),
		"southwest" :__DIR__"xiaolu"+(random(3)+6),
        ]));


	set("cost", 1);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
