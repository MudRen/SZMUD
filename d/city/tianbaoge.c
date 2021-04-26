// Code of ShenZhou
// Room: /city/tianbaoge.c
// by aln 2 / 98
// modified by sdong, 10/19/1999

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�챦��");
        set("long", @LONG
����ԭ�Ǳ���һ��������꣬��õ����ϰ徭Ӫ���ƶ����ա��ڴ�֮����
����ĳ��ְ��������¹�������棬����֪Ϊ���ְ����ˡ����һλ���̽��˵�
���£�װ����һ���������¿�ҵ�ˡ���˵�����������֮�⣬�����ṩһЩ�µ�
����
LONG
        );

        set("exits", ([
                "west" : __DIR__"beidajie1",
        ]));
         set("objects", ([
                "/clone/npc/publisher" : 1,
        ]));

        set("no_fight",1);
        set("no_sleep",1);
//        set("day_shop", 1);
        set("cost", 0);
        setup();
}

void reset()
{
        ::reset();
        set("no_clean_up", 1);
}
