// Code of ShenZhou
// /d/zhongnan/liangong1.c ������
// by sdong

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�������ǹ����������ڹ������ж���ѧ�鼮֮�������ڲ����ر�
���裬��������й�ʱ���ģ������˽��ȡ����������᷿����������
������
LONG
        );

        set("exits", ([
                "west" : __DIR__"yinwutin",
                "east" : __DIR__"nanqinshi",
        ]));

        set("cost", 0);
        setup();

}

int valid_leave(object me, string dir)
{
        if ( me->query("gender") == "Ů��" && dir == "east" && !wizardp(me) )
                return notify_fail("������㣬�������᷿��\n");

        return ::valid_leave(me, dir);
}
