// Code of ShenZhou
// Room: /d/heimuya/clifftop.c
// Date: fear 1999/12/18
#include <ansi.h>

inherit ROOM;




void create()
{
        set("short", "�¶�");
        set("long", @LONG
������Ǻ�ľ�¶��ˣ������µ�������ȱ�������
�ƣ������御ͷ���¶����Ϸ���һֻ����¨�������¶�
�н������̣����Խ���¨����ȥ��
LONG
        );

        set("exits", ([
                "southeast" : __DIR__"pailou",
                "enter" : __DIR__"basket",
        ]));

        set("outdoors", "heimuya");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

