// Code of ShenZhou
// Room: /d/heimuya/northgate.c
// Date: fear 99/12/08

inherit ROOM;




void create()
{
        set("short", "ƽ���ݱ���");
        set("long", @LONG
������ƽ���ݵı��ţ�ƽʱ������˱Ƚ��٣�����
�����ĵġ�����ȥ���Կ���һƬ���֡�
LONG
        );

        set("exits", ([
                "north" : __DIR__"forest",
                "south" : __DIR__"northstreet1",
        ]));

        set("outdoors", "heimuya");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

