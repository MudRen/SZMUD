// Code of ShenZhou
// Room: /d/heimuya/center.c
// Date: fear 99/12/08

inherit ROOM;




void create()
{
        set("short", "ƽ��������");
        set("long", @LONG
������ƽ���ݵ����ģ�����ƽ���ݵĽ�ͨҪ�塣��
�������������������֡�����������������ʯ���̳ɵ�
���ֵ�·��
LONG
        );

        set("exits", ([
                "west" : __DIR__"weststreet1",
                "east" : __DIR__"eaststreet1",
                "north" : __DIR__"northstreet1",
        ]));

        set("outdoors", "heimuya");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

