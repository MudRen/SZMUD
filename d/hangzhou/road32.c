// Code of ShenZhou
// ���
// Dong  11/03/1996.

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{       set("short", "���");
        set("long", @LONG
������߱�ֲ���ɣ���Ŀ�Դ䣬�ȸ���ѩ������Ϊ������ѩ�ɡ���
�����Ǻ鴺�ţ����߱㵽�������£��ϱ�һֱ��ǰ�ɴ����Ϻ�������
LONG);
        set("exits", ([ /* sizeof() == 2 */ 
                  "east" : __DIR__"hongchun",
                  "southup" : __DIR__"road41",
                  "west" : __DIR__"road33", 
                  "northwest" :  "/d/taihu/nanxun",
                ])
        );
	set("cost", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
