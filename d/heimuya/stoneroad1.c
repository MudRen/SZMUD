// Code of ShenZhou
// Room: /d/heimuya/stoneroad1.c
// Date: fear 99/12/08

inherit ROOM;




void create()
{
        set("short", "ʯ·");
        set("long", @LONG
������ʯ·��·�����׵�ɽʯ�����Ѫ���ұ���һ
Ƭ��̲��ˮ���ļ����Ǳ�������������̲�����ϱ�ȥ��
һƬ��ѹѹ�����֡�
LONG
        );

        set("exits", ([
                "northwest" : __DIR__"stoneroad2",
                "south" : __DIR__"heimulin5",
        ]));

        set("outdoors", "heimuya");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

