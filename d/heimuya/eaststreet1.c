// Code of ShenZhou
// Room: /d/heimuya/eaststreet1.c
// Date: fear 99/12/08

inherit ROOM;




void create()
{
        set("short", "������");
        set("long", @LONG
����ƽ���ݵĶ����֣�·������������������ֵ�
�����м����У����ױ���ƽ���ݵ����ġ�
LONG
        );

        set("exits", ([
                "west" : __DIR__"center",
                "east" : __DIR__"eaststreet2",
                "north" : __DIR__"mihang",
        ]));

        set("outdoors", "heimuya");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

