//Cracked by Roath
// Room: /d/beijing/kedian.c

#include <ansi.h>
#include "/d/beijing/beijing_defs.h"
inherit ROOM;


void create()
{
        set("short", HIC"�����ջ"NOR);
        set("long", @LONG
���Ǿ�����һ����ͨ�Ŀ�ջ�����ڿ������ţ�����ǳ���¡������ο�
��ѡ��������ţ���С����������æ������ת���Ӵ�����ǻ�����Ŀ��ˡ���
�����һ������(paizi)��
LONG
        );

        set("valid_startroom", 1);
        set("no_sleep_room",1);
        set("item_desc", ([
                "paizi" : "¥���ŷ���ÿҹ��ʮ��������\n",
        ]));

        set("objects", ([
                __DIR__"npc/kedian_xiaoer" : 1,
        ]));

        set("exits", ([
                "up" : __DIR__"kedian2",
                "north" : __DIR__"tianqiao",
        ]));

        setup();
	set("no_fight", 0);

        "/clone/board/beijing_b"->foo();
}

int valid_leave(object me, string dir)
{
        string id;
        int i;

        if(me == present("xiao er"))
                return ::valid_leave(me, dir);

        if(objectp(present("xiao er", environment(me)))) {
                if ( !me->query_temp("rent_paid") && dir == "up" )
                return notify_fail("��С��һ�µ���¥��ǰ������һ���������ţ����ס����\n");

                if ( me->query_temp("rent_paid") && dir != "up" )
                return notify_fail("��С���ܵ��ű���ס���͹��Ѿ��������ӣ����᲻ס��������أ�
���˻���ΪС���ź����أ�\n");
        }

        return ::valid_leave(me, dir);
}

void init()
{
    if (random(3) == 1) 
        HELPER->clonehere_with_limit(this_object(), "/d/beijing/obj/jiaozi", 4);
}

