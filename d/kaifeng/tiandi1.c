// Code of ShenZhou
// chchong 2002/02/01
// /d/kaifeng/tiandi1.c

inherit ROOM;

void create()
{
    int i;
        set("short", "���");
        set("long", @LONG
������ľ����ϡ�裬��Զ����һЩ��ׯ�������������𡣴�ׯ��Χ
��һ������أ�������һЩ���ڸ�����ũ�ˡ�
LONG
        );

        set("exits", ([
                "north" : __DIR__"nanmen",
                "south" : __DIR__"tiandi2",
        ]));

        set("outdoors","kaifeng");
	set("cost", 2);
        setup();
	replace_program(ROOM);
}

