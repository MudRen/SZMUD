// Code of ShenZhou
// room: liang.c

#include <room.h>

inherit ROOM;

void create()
{ 
       set("short","�����");
       set("long", @LONG
����ڽ�����ϣ��ܼ���յ����ӽ�����ߣ�������ĬĬ΢Ц��
LONG
     );
        set("exits", ([
                "down" : __DIR__"hongdian",
        ]));       
	set("objects", ([
                __DIR__"obj/klguan" : 2,
                __DIR__"obj/rtlian" : 2,
                __DIR__"obj/lubo" : 2,
        ]));
	set("cost", 1);
        setup();
}

