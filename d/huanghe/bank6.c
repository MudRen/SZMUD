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
		"northeast" : __DIR__"bank7",
		"southwest" : __DIR__"bank5",
                "south" : __DIR__"tccunko",
        ]));

	set("objects", ([
		__DIR__"npc/qiu.c" : 1,
	]));

	set("outdoors", "huanghe");
	set("cost", 2);
        setup();

	replace_program(ROOM);
}

