// Code of ShenZhou
// Room: /d/heimuya/hillroad1.c
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
                "westdown" : __DIR__"shuitan2",
                "northup" : __DIR__"hillroad2",
        ]));

        set("outdoors", "heimuya");
        set("cost", 3);
        setup();
        replace_program(ROOM);
}

