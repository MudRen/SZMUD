// Code of ShenZhou
// Room: /d/heimuya/stonechannel.c
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
                "southeast" : __DIR__"stoneroad2",
                "north" : __DIR__"stonechannel2",
        ]));

        set("outdoors", "heimuya");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

