// Code of ShenZhou
// Room: /d/heimuya/hillroad4.c
// Date: fear 1999/12/08

inherit ROOM;




void create()
{
        set("short", "ɽ��");
        set("long", @LONG
����ɽ��ת���������ϣ����Ƽ��գ����Ա�������
��ȡ�
LONG
        );

        set("exits", ([
                "southdown" : __DIR__"hillroad3",
                "north" : __DIR__"zongtan",
        ]));

        set("outdoors", "heimuya");
        set("cost", 3);
        setup();
        replace_program(ROOM);
}

