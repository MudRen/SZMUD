// Code of ShenZhou
// liangcang.c ����
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
	set("long", @LONG
��������ռ�ؿ��Ŀⷿ���ѷ��Ŷѻ���ɽ�ľ������굽��������Ҳ����
��֮�á����ڲֹ����٣����������ͽ�Ŀ��ӡ�
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"northeast" : __DIR__"mixiang",
		"south" : __DIR__"citong_e1",
	]));

        set("objects", ([ 
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
        ]));

        set("no_clean_up", 0);

	set("cost", 2);
        setup();
}

int valid_leave(object me, string dir)
{
        if ( objectp(present("wu jiang",environment(me))) && dir == "northeast" )
                return notify_fail("�佫��ȵ���������������˵Ȳ����ɴ˾�����\n");

        if ( objectp(present("guan bing",environment(me))) && dir == "northeast" )
                return notify_fail("�ٱ���ȵ���������������˵Ȳ����ɴ˾�����\n");

        return ::valid_leave(me, dir);
}

