// Code of ShenZhou
// Room: /d/heimuya/northstreet1.c
// Date: fear 1999/12/08

inherit ROOM;




void create()
{
        set("short", "������");
        set("long", @LONG
����ƽ���ݵı����֣���ʯ·������������������
�֡������и����ĵ��̡���߿��Կ���ƽ���Ƶ�����ӣ�
Ʈ��������㡣�ұ��мҵ��̣�������ȥ����ͨ��ƽ��
�ݵı��š�
LONG
        );

        set("exits", ([
                "east" : __DIR__"dangpu",
                "west" : __DIR__"jiudian",
                "north" : __DIR__"northgate",
                "south" : __DIR__"center",
        ]));

        set("outdoors", "heimuya");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

