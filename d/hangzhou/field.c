// Code of ShenZhou
// Jay 9/04/96

inherit ROOM;

void create()
{
    int i;
        set("short", "���");
        set("long", @LONG
������һƬũ���Զ����һЩ��ׯ�������������𡣴�ׯ��Χ
��һ������أ�������һЩ���ڸ�����ũ�ˡ�
LONG
        );

        set("exits", ([
		"south" : __DIR__"road34",
		"north" : "/d/wudang/wdroad1",
        ]));

	set("outdoors","forest");
        set("objects", ([
                "/clone/beast/banjiu" : random(2),
        ]));

	set("cost", 2);
        setup();
	replace_program(ROOM);
}

