// Code of ShenZhou
// Room: /d/heimuya/weststreet1.c
// Date: fear 99/12/08

inherit ROOM;




void create()
{
        set("short", "������");
        set("long", @LONG
����ƽ���ݵ������֣��ߵ����Ͽ�������С������
���������߹����棬�мҿ͵꣬�����м��ӻ��̡�����
�����߹��ܶ��ˣ��������֡�
LONG
        );

        set("exits", ([
                "east" : __DIR__"center",
                "west" : __DIR__"weststreet2",
                "north" : __DIR__"kedian",
                "south" : __DIR__"zahuopu",
        ]));

        set("outdoors", "heimuya");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

