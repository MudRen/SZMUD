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
		"east" : __DIR__"bank3",
		"west" : __DIR__"bank1",
        ]));

	set("outdoors","forest");
	set("cost", 2);
        setup();
	replace_program(ROOM);
}

