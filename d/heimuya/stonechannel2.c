// Code of ShenZhou
// Room: /d/heimuya/stonechanne2.c
// Date: fear 99/12/08

inherit ROOM;




void create()
{
        set("short", "ʯ��");
        set("long", @LONG
��������խ������ʯ������·����ʯ����ǽ���м�
����һ����Լ��ߵ�ʯ����
LONG
        );

        set("exits", ([
                "south" : __DIR__"stonechannel1",
                "north" : __DIR__"shuitan1",
        ]));

        set("outdoors", "heimuya");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

