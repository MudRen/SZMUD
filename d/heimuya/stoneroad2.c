// Code of ShenZhou
// Room: /d/heimuya/stoneroad2.c
// Date: fear 99/12/08

inherit ROOM;




void create()
{
        set("short", "ʯ·");
        set("long", @LONG
������ʯ·��·�����׵�ɽʯ�����Ѫ���ұ���һ
Ƭ��̲��ˮ���ļ����Ǳ�������������̲��ǰ��Զ����
����һ����С��ʯ����
LONG
        );

        set("exits", ([
                "southeast" : __DIR__"stoneroad1",
                "northwest" : __DIR__"stonechannel1",
        ]));

        set("outdoors", "heimuya");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

