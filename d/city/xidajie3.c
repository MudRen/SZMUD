// Code of ShenZhou
// Room: /city/xidajie3.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
������������ϣ�����Ľ���Ҫ�ȱ𴦵ĸɾ������ࡣ��Ϊ�������š���Ӫ
���ܱ����������Ƕ�ϲ��ס��������߾����ĵ�û�м������ˣ�������������
ͨ�����⡣����������Զͼ����ġ������ھ֡����ڱ�����һ�������ûʵĴ�լ
Ժ��
LONG );
        set("outdoors", "city");
        set("no_clean_up", 0);
        set("exits", ([
                "east"  : __DIR__"xidajie2",
                "south" : __DIR__"biaoju",
                "west"  : __DIR__"ximen",
                "north" : __DIR__"caizhu",
        ]));

        set("objects", ([
                "/d/quanzhen/npc/youfang": 1,
        ]));

        setup();
        replace_program(ROOM);
}
