// Code of ShenZhou
// Room: /d/heimuya/forest.c
// Date: fear 99/12/08

inherit ROOM;




void create()
{
        set("short", "����");
        set("long", @LONG
����ƽ���ݽ�������֣�������ʱ���кܶ�Ұ�޳�
û���ֱ��������������������������������ô̴̵�
�����ۣ�׷����Ұ�á�
LONG
        );

        set("exits", ([
                "east" : __DIR__"heimulin1",
                "south" : __DIR__"northgate",
        ]));

        set("objects", ([
                "/clone/beast/yetu" : 1,
        ]));

        set("outdoors", "heimuya");
        set("cost", 2);
        setup();
        replace_program(ROOM);
}

