// Code of ShenZhou
// Room: /d/heimuya/heimulin8.c
// Date: fear 99/12/08

inherit ROOM;




void create()
{
        set("short", "��ľ��");
        set("long", @LONG
����һ�����ص����֣���Χ����������Ĳ��������
�����Ｋ�����������������۾�Ҳ������������������
��·��һ����紵�����ң���Ҷ����ɳɳ������������
���������� 
LONG
        );

        set("exits", ([
                "north" : __DIR__"stoneroad1",
                "east" : __DIR__"heimulin5",
                "south" : __DIR__"heimulin3",
                "west" : __DIR__"heimulin5",
        ]));

        set("outdoors", "heimuya");
        set("cost", 2);
        setup();
        replace_program(ROOM);
}
