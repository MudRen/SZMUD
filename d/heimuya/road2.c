// Code of ShenZhou
// Room: /d/heimuya/road2.c
// Date: fear 99/12/08

inherit ROOM;




void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
����һ��ƽֱ�Ĵ������������ʯ���̳ɣ����Զ�
��Ũ�ܵ����֡����ϲ�ʱ�������������������Ƿ�æ��
LONG
        );

        set("exits", ([
                "southeast" : __DIR__"road1",
                "northwest" : __DIR__"smallhill1",
        ]));

        set("outdoors", "heimuya");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

