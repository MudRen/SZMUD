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
                "southwest" : __DIR__"forest5",
		"east" : __DIR__"field2",
        ]));

	set("outdoors","forest");
	set("objects", ([
		"/clone/beast/banjiu" : random(2), 
	]));

	set("cost", 2);
        setup();
	replace_program(ROOM);
}

