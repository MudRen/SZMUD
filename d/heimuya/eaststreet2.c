// Code of ShenZhou
// Room: /d/heimuya/eaststreet2.c
// Date: fear 99/12/08

inherit ROOM;




void create()
{
        set("short", "������");
        set("long", @LONG
����ƽ���ݵĶ����֣������кܶ��˳���������Զ
�����������ã���������ʯ��·��ֱ����չ��ȥֱͨ��
�š�
LONG
        );

        set("exits", ([
                "west" : __DIR__"eaststreet1",
                "east" : __DIR__"eastgate",
                "north" : __DIR__"pocitang",
        ]));

        set("outdoors", "heimuya");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

