// Code of ShenZhou
// ���� /d/shenlong/changlang.c
// ALN Sep / 97

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ�����ȣ�����ͨ������������Ƿ嶥����Χ��������Ҷ�����٣���
�������Сʯ�ʿɹ�����Ϣ��һЩ������������������������������̵ĵ��ӣ�
������������̸����ʲô��
LONG
        );
        set("cost", 1);
        set("outdoors", "shenlong");

        set("exits", ([
                "east": __DIR__"tingkou",
                "west": __DIR__"fengding",
        ]));

        set("objects", ([
                "/kungfu/class/shenlong/fang" : 1,
        ]));

        setup();
}
