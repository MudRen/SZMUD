// /d/kaifeng/kezhan.c
//by bravo
inherit ROOM;

void create()
{
        set("short", "�ޱ߿�ջ");
        set("long", @LONG       
    �ޱ߿�ջ�Ǻ������Ŀ͵꣬����ǳ���¡������οͶ�ѡ����
����ţ��������������������صķ������顣��С����������æ��
����ת�����صĵط��ٻ�����ʵ������˳�������ǿ��⸮�ٰ�Ŀ�ջ,
�Ӵ��Ÿ�����ԥ�Ĺٲ����ˡ�ǽ�Ϲ���һ������(paizi)��
LONG
        );

        set("valid_startroom", 1);
        set("no_sleep_room",1);

        set("item_desc", ([
                "paizi" : "¥���ŷ���ÿҹ����������\n",
        ]));

        set("objects", ([
         "d/city/npc/xiaoer" : 1,
              ]));

        set("exits", ([
          "northwest" : __DIR__"sroad2e",
                "up" : __DIR__"kezhan2",
        ]));

        setup();
        
}

int valid_leave(object me, string dir)
{

        if ( !me->query_temp("rent_paid") && dir == "up" )
                return notify_fail("���ס,���ұⰡ��\n");

        if ( me->query_temp("rent_paid") && dir == "west" )
                return notify_fail("�͹��Ѿ��������ӣ���ô��ס��������أ����˻���ΪС���ź����أ�\n");

        return ::valid_leave(me, dir);
}

