// room /d/taishan/shangwu.c
//updated by Lara 2001/10/14
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������һ������Ľ�����ǰ��ֻ��������������������������������
���ԡ���������д�ĺ����پ����㿴��������������������ģ��������ͻ
Ȼ����о�һ�ɺ����������ܡ����ߴ���һ������ʳָ�󶯵�����������
����������¥��������������Ӣ�۴��㳡�������͵�����ͬ������ĵ�
���ˡ�
LONG
        );

        set("exits", ([
                "southdown" : __DIR__"shanlu",
                "north" : __DIR__"dianmen",
         "east" : __DIR__"guangchang",
         "west" : __DIR__"taotielou",
]));

        set("objects",([
                __DIR__"npc/yishi" : 2,
        ]));

        set("no_clean_up", 0);
        set("outdoors", "taishan");

        set("cost", 1);
        setup();
        replace_program(ROOM);
}











