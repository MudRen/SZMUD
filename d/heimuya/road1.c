// Code of ShenZhou
// Room: /d/heimuya/road1.c
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
                "southeast" : "/d/beijing/yidao3",
                "northwest" : __DIR__"road2",
        ]));

        set("outdoors", "heimuya");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

