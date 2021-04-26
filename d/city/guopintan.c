// Code of ShenZhou
// Room: /city/guopintan.c
// YZC 1996/11/13 

inherit ROOM;

void create()
{
        set("short", "��Ʒ̯");
        set("long", @LONG
���������ݳ���һ����ˮ���߲˵�С̯�ӡ���������Ĵ������ͨ���գ�
ż���м�������Ĳ�ү��վ��ˮ��̯��һ�����ģ�һ�ߴ�ڴ�ڵؿ���̯��Т
����ˮ���������������ֵĶ��ϴ�֡�
LONG
        );
        set("outdoors", "city");

        set("exits", ([
                "north" : __DIR__"dongnanjie",
//              "west" : __DIR__"nandajie2",
        ]));

        set("objects", ([
                __DIR__"npc/xiao-fan" : 1,
                __DIR__"npc/xiangshi" : 1,
        ]));

        set("cost", 0);
        setup();
}
