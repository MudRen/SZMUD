// Code of ShenZhou
// Room: /d/heimuya/cliff.c
// Date: fear 1999/12/18
#include <ansi.h>

inherit ROOM;




void create()
{
        set("short", "����");
        set("long", @LONG
ǰ����һ�����͵����£��ͱ�������������ȣ���
�¶���������ɽ�����Ϸ���һֻ����¨�����¶����н�
�����̣����Խ���¨����ȥ��
LONG
        );

        set("exits", ([
                "south" : __DIR__"shimen",
                "enter" : __DIR__"basket",
        ]));

        set("outdoors", "heimuya");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

