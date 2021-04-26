// Code of ShenZhou
// Room: /city/kedian.c
// YZC 1995/12/04

inherit ROOM;

// Marz added indecent or inapproapriate id check here :
string* Banned_id = ({
        "ufk",
        "none",
});


void create()
{
        set("short", "�м��ջ");
        set("long", @LONG
��ҿ�ջ�������������ģ���������ǳ���¡����֮��Ǯ���������ǳ�
������ο���ŵ���ѡ��¶������߰������ӣ����̾����˵��ڴ˽���������
���ﲻ�����������õ�С�������ػ��д����ķ����͡�
LONG
        );

//      set("no_fight", 1);
        set("valid_startroom", 1);
        set("no_sleep_room",1);

        set("item_desc", ([
                "paizi" : "¥���ŷ���ÿҹ����������\n",
        ]));

        set("objects", ([
                "/d/quanzhou/npc/qzxiaoer" : 1,
        ]));

        set("exits", ([
                "south" : __DIR__"eroad2",
                "west" : __DIR__"majiu",
                "up" : __DIR__"changankezhan",
]));
        set("outdoors", "changan");
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

                if ( me->query_temp("rent_paid") && dir == "west" )
                return notify_fail("��С���ܵ��ű���ס���͹��Ѿ��������ӣ����᲻ס��������أ�
���˻���ΪС���ź����أ�\n");
        }

        if( present("xiao er", me) && dir="west" )
                return notify_fail("�ö˶˵��������С��������ȥ����\n");

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
