// Code of ShenZhou
// Room: /city/beimen.c
// YZC 1995/12/04 

#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
        set("short", "����");
        set("long", 
"�������Զ�����������ݳ��ˡ���������������˴�����������������ŵ�
�ٱ������¶����㡣����������ȥ��һƬ�����ľ��󡣱�����һ����ʯ�������
����������ǽ�Ϲ���һ����ʾ(gaoshi)��\n"
        );

        set("item_desc", ([
                "gaoshi" : (:look_gaoshi:),
        ]));

        set("exits", ([
                "south" : __DIR__"beidajie2",
              "north" : "/d/city/road1",
                "east" : __DIR__"beijiao1",
                "west" : __DIR__"beijiao3",
        ]));
        set("objects", ([
                __DIR__"npc/wujiang" : 1,
                __DIR__"npc/bing" : 2,
        ]));
        set("outdoors", "city");
        set("cost", 1);
        setup();
}

string look_gaoshi()
{
        return FINGER_D->get_killer() + "\n�㽭�ᶽ\n�����\n";
}
int valid_leave(object me, string dir)
{
        if (dir =="south" )
        if(present("guan bing", (environment(me)))
        && me->query_condition("killer") > 0)
                return notify_fail("�ٱ����еĵ���ס�����ȥ·��\n");
        return ::valid_leave(me, dir);
}
