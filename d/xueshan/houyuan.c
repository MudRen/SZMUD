// Code of ShenZhou
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "��Ժ");
        set("long", @LONG
�����Ǻ�Ժ��ǽ���Ϸ���һ���Ħ�Ǵ�������͵����ϰ�����书
�õ�ľ�ˡ������ǻ���ס�İ�Ƿ¥������������������ǽ��Ժ��
LONG
        );
        set("exits", ([
                "south" : __DIR__"jingang",
                "north" : __DIR__"angqian",
		"west" : __DIR__"tianlong",
		"east" :__DIR__"houyuan2",
        ]));

        set("objects", ([
		"/d/xueshan/npc/mu-ren" : 1
	]));
	set("cost", 1);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
