// Code of ShenZhou
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǹ�Ӧȫ����ʳ�����ڣ������͹��������������æµ���Ա��м�����
���������ֵľ���
LONG
        );
        set("exits", ([
                "west" : __DIR__"zoulang",
        ]));
	set("objects", ([
		__DIR__"npc/xlama2" : 1,
		__DIR__"obj/buttertea" : 3,
	]));


	set("cost", 0);
        setup();
        set("outdoors","qilian-shan");
}
int valid_leave(object me, string dir)
{

        if( dir == "west" && present("tea", me) )
        {
                return notify_fail("���ż������������ !\n");
        }
        return ::valid_leave(me, dir);
}
