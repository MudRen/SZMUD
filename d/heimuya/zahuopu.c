// Code of ShenZhou
// Room: /d/heimuya/zahuopu.c
// Date: fear 1999/12/08
#include <ansi.h>

inherit ROOM;




void create()
{
        set("short", "�ӻ���");
        set("long", @LONG
�����Ǽ����ӻ���С���ӣ���������˸���ʽ����
���������Ŀ��ǽ�Ϲ���һ���¾ɵ�ľ��(mupai)��
LONG
        );

        set("item_desc", ([
                "mupai": HIG"��Ǯ������ͯ�����ۡ�\n"NOR,
        ]));

        set("exits", ([
                "north" : __DIR__"weststreet1",
        ]));

        set("objects", ([
                __DIR__"npc/shopkeeper": 1,
        ]));

        set("cost", 1);
        set("day_shop", 1);
        setup();
        replace_program(ROOM);
}

