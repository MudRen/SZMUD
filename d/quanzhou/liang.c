// Code of ShenZhou
// room: liang.c
//Jay 4/7/96

#include <room.h>

inherit ROOM;

void create()
{ 
       set("short","������լ����");
       set("long", @LONG
�����������ҵķ��������¹��ƣ���Χ����Щ��ľͷ��ש�ߡ�ͻȻ���
�����깴���һ�����ġ�
LONG
     );
        set("exits", ([
                "down" : __DIR__"mishi",
        ]));       
        set("objects", ([
                __DIR__"obj/jiasha" : 1,
                "/d/xingxiu/npc/snake" :1,
        ]));       

	set("cost", 2);
        setup();
}
