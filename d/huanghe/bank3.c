// Code of ShenZhou
// Jay 9/04/96

inherit ROOM;

void create()
{
    int i;
        set("short", "�ƺӰ���");
        set("long", @LONG
�����ǻƺӰ��ߡ��ƺ����ʵ�����Ѿ���ɳ�����ˡ���ɫ
�ĺ�ˮ�ںӴ��﷭���ţ������ţ�����һ�����޴�����ѡ�
LONG
        );

        set("exits", ([
		"west" : __DIR__"bank2",
		"east" : __DIR__"bank4",
                "north" : "/d/kaifeng/hhbian",
        ]));

	set("outdoors","forest");
	set("cost", 2);
        setup();
	replace_program(ROOM);
}

