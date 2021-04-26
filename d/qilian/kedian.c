// Code of ShenZhou
// Room: /city/kedian.c
// YZC 1995/12/04
#include <ansi.h>
inherit ROOM;

// Marz added indecent or inapproapriate id check here :
string* Banned_id = ({
        "ufk",
        "none",
});


void create()
{
        set("short", HIC"�͵�"NOR);
        set("long", @LONG
����һ�ҵ��ؾ��񿪵ļ�ëС�꣬¥����Щ±�˺��Ӿƣ�¥�����ǿ�
���������ڽ�����ɽ��ǰ��Ψһ��Ϣ֮�����������䣬��ҩ�͵Ƚ��ڴ�
������ʱ���ɿ���һ����Ѱ�ɷõ�֮����ǽ����һ������(paizi)��
������һ����ǡ�
LONG
        );

        set("valid_startroom", 1);
	set("outdoors", "qilian");
        set("no_sleep_room",1);

        set("item_desc", ([
                "paizi" : "¥���ŷ���ÿҹ����������\n",
        ]));

        set("objects", ([
                __DIR__"npc/qxiaoer" : 1,
        ]));

        set("exits", ([
                "east" : __DIR__"yongdeng",
		"up" : __DIR__"kedian2",
		"west" : __DIR__"majiu",
        ]));

        setup();
//      "/clone/board/kedian_b"->foo();
//      "/clone/board/jiangpai_b"->foo();
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

                if ( me->query_temp("rent_paid") && dir == "east" )
                return notify_fail("��С���ܵ��ű���ס���͹��Ѿ��������ӣ����᲻ס��������أ�
���˻���ΪС���ź����أ�\n");
        }

        id = (string)me->query("id");
        for (i = 0; i < sizeof(Banned_id); i++)
        {
        if (id == Banned_id[i])
        {
                me->set("startroom", "/d/death/block");
                me->move("/d/death/block");
                return notify_fail("�ٺ٣��������ܵ�����ȥ����\n");
        }
        }

        return ::valid_leave(me, dir);
}
