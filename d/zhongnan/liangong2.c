// Code of ShenZhou
// /d/zhongnan/liangong2.c ������
// by sdong

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�������ǹ����������ڹ������ж���ѧ�鼮֮�������ڲ����ر�
���裬��������й�ʱ���ģ������˽��ȡ�������Ů�᷿���ϱ��Ǿ�
�ҡ�
LONG
        );

        set("exits", ([
                "north" : __DIR__"nyuqinshi",
                "south" : __DIR__"jinshi",
        ]));

        set("cost", 0);
        setup();

}

int valid_leave(object me, string dir)
{
        if ( me->query("gender") == "����" && dir == "north" && !wizardp(me) )
                return notify_fail("������㣬����Ů�᷿��\n");

        return ::valid_leave(me, dir);
}
