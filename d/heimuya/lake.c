// Code of ShenZhou
// Room: /d/heimuya/lake.c
// Date: fear 1999/12/08
#include <ansi.h>

inherit ROOM;




void create()
{
        set("short", HIC"С��"NOR);
        set("long", @LONG
������ƽ���ݽ����һ��С�������Զ��Ǵ�������
��ˮ��΢�������߳�����Ұ�����������ˡ�С��������
����԰��������ׯ��ũ���ڲ�԰����æ�Ž�ˮ������Χ
���м���ũ�ᡣ
LONG
        );

        set("exits", ([
                "east" : __DIR__"nongshe1",
                "north" : __DIR__"nongshe2",
                "southwest" : __DIR__"smallhill2",
        ]));

        set("objects", ([
                "/d/emei/obj/flower" : 1,
        ]));

        set("outdoors", "heimuya");
        set("cost", 2);
        setup();
        replace_program(ROOM);
}

