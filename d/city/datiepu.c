           // Room: /city/datiepu.c
// YZC 1995/12/04 
// RYU 1997/3/18

// Last Modify by Scatter
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����һ�Ҽ�ª�Ĵ����̣����İ���һ����¯��¯��������յ�һƬͨ�죬�� 
һ�߽�ȥ�͸е�������ȡ�ǽ�Ƕ��������깤��δ�깤�Ĳ˵���������������ذ�ס����׵��һλ������ͷ�󺹻�����������ר����־���ڴ�����
LONG
        );

        set("exits", ([
                "north" : __DIR__"dongdajie2",
                  "south" : "/newjob/tiejiang/datiechang",
]));
        set("objects", ([
                __DIR__"npc/tiejiang" : 1,
                __DIR__"npc/gongjiang" : 1,
        ]));

        set("day_shop", 1);
        set("cost", 0);
        setup();
}

int valid_leave(object me, string dir)
{
        if( present("wang tiejiang", me) )
                return notify_fail("����մ�������ʲô���۸���ʵ�˰���\n");

        return ::valid_leave(me, dir);
}

