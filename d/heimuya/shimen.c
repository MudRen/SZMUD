// Code of ShenZhou
// Room: /d/heimuya/shimen.c
// Date: fear 1999/12/18
#include <ansi.h>

inherit ROOM;




void create()
{
        set("short", HIR"ʯ��"NOR);
        set("long", @LONG
������һ����ʯ�ţ�ֻ�����Կ������д��֣�����
�ǡ��ĳ���á��������ǡ�����Ӣ����������Ͽ��š�
���¹������ĸ�����֡�
LONG
        );

        set("exits", ([
                "westdown" : __DIR__"shiji3",
                "north" : __DIR__"cliff",
        ]));

        set("outdoors", "heimuya");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

