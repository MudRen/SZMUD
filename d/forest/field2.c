// Code of ShenZhou
// Jay 9/04/96

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
                "south" : __DIR__"forest3",
		"east" : __DIR__"field3",
		"west" : __DIR__"field1",
        ]));

	set("outdoors","forest");
	set("cost", 2);
        setup();
	replace_program(ROOM);
}

