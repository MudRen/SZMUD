// Code of ShenZhou
// Room: /d/heimuya/hillroad2.c
// Date: fear 1999/12/08

inherit ROOM;




void create()
{
        set("short", "ɽ��");
        set("long", @LONG
������������ɽ�����Ա���ľ�ߴ󣬵�·���Ƕ��͡�
LONG
        );

        set("exits", ([
                "southdown" : __DIR__"hillroad1",
                "eastup" : __DIR__"hillroad3",
        ]));

        set("outdoors", "heimuya");
        set("cost", 3);
        setup();
        replace_program(ROOM);
}

