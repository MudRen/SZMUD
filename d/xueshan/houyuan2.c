// Code of ShenZhou
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "��Ժ");
        set("long", @LONG
�����Ǻ�Ժ������ǽ������һ��ˮ��(well)�����������±�Ժ��
LONG
        );
        set("exits", ([
                "south" : __DIR__"lazhang",
		"west" :__DIR__"houyuan",
        ]));
	set("objects", ([
		"/clone/weapon/falun": 1,
	]));
	set("item_desc", ([
                "well" : "����һ��ˮ����\n"
        ]));
        set("resource/water", 1);

	set("cost", 1);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
