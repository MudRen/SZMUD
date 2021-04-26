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
        set("short", HIC"�����"NOR);
        set("long", @LONG
һ�ҵ͵��ĳ����ջ�������൱�¾ɣ��ܲ����ۣ��������ڼ�Ǯ����������
�ڱ��ŵĽ�ͨҪ���ϣ����̾�����ѡ��������ţ�����Ҳ�൱������Ҳ������
������������صķ������顣ǽ�Ϲ���һ������(paizi)��
LONG
        );

//      set("no_fight", 1);
        set("valid_startroom", 1);
        set("no_sleep_room",1);

        set("item_desc", ([
                "paizi" : "¥���ŷ���ÿҹ����������\n",
        ]));

        set("objects", ([
                __DIR__"npc/xiaoer" : 1,
        ]));

        set("exits", ([
                "west" : __DIR__"nandajie",
		"up" : __DIR__"kedian2",
        ]));

        setup();

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
