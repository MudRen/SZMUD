// Code of ShenZhou
// Room: /d/heimuya/shiji1.c
// Date: fear 1999/12/08
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
                "northup" : __DIR__"shiji2",
                "southwest" : __DIR__"zongtan",
        ]));

        set("outdoors", "heimuya");
        set("cost", 2);
        setup();
        replace_program(ROOM);
}

