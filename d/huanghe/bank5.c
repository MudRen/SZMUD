// Code of ShenZhou
// Jay 9/04/96

inherit ROOM;

void create()
{
    int i;
        set("short", "�ƺӰ���");
        set("long", @LONG
�����ǻƺӰ��ߡ��ƺ����ʵ�����Ӵ���������ɫ�ĺ�ˮ��
����������ȥ��ʹ������������ˮʱ�Ŀ�����
LONG
        );

        set("exits", ([
		"northeast" : __DIR__"bank6",
		"east" : "/d/taishan/daizong",
		"southwest" : __DIR__"bank4",
        ]));

	set("outdoors","forest");
	set("cost", 2);
        setup();
	replace_program(ROOM);
}

