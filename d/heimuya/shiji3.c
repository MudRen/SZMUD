// Code of ShenZhou
// Room: /d/heimuya/shiji3.c
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
                "westdown" : __DIR__"shiji2",
                "eastup" : __DIR__"shimen",
        ]));

        set("outdoors", "heimuya");
        set("cost", 2);
        setup();
        replace_program(ROOM);
}

