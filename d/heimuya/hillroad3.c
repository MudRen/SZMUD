// Code of ShenZhou
// Room: /d/heimuya/hillroad3.c
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
                "westdown" : __DIR__"hillroad2",
                "northup" : __DIR__"hillroad4",
        ]));

        set("outdoors", "heimuya");
        set("cost", 3);
        setup();
        replace_program(ROOM);
}

