// Code of ShenZhou
// Room: /d/heimuya/shiji2.c
// Date: fear 1999/12/18
#include <ansi.h>

inherit ROOM;




void create()
{
        set("short", "ʯ��");
        set("long", @LONG
�������µ�ʯ����������һ�����š���բ֮ǰ����
���½̽��ڰ��أ�������ơ�
LONG
        );

        set("exits", ([
                "southdown" : __DIR__"shiji1",
                "eastup" : __DIR__"shiji3",
        ]));

        set("outdoors", "heimuya");
        set("cost", 2);
        setup();
        replace_program(ROOM);
}

