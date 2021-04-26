// Code of ShenZhou
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "��ѩɽɽ·");
        set("long", @LONG
��ѩɽ��´�ĵ��Ʋ������ߣ���Χ����һЩСɽ��������һ
����Ժ��ɽ�������Ե��쳣�ߴ���Ժ��ƽ�����ͣ����ɴ�ʯ���ɣ�
ǽ���ʵ������խС�� 
LONG
        );
        set("exits", ([
                "westup" : __DIR__"shanmen",
                "north" : __DIR__"beilu",
        ]));
	set("objects", ([
		__DIR__"npc/tuying": 2,
		__DIR__"npc/lu" :1,
		__DIR__"npc/shui" : 1,
	]));

	set("cost", 3);
        setup();
        set("outdoors","qilian-shan");
}
int valid_leave(object me, string dir)
{
	if (dir =="westup" ) 
	me->set_temp("mark/comin", 1);

	return ::valid_leave(me, dir);
}
