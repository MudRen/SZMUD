// Code of ShenZhou
// Jay 9/04/96

inherit ROOM;

void create()
{
        set("short", "�ƺӰ���");
        set("long", @LONG
�����ǻƺӰ��ߡ��ƺ����ʵ�����Ѿ���ɳ�����ˡ���ɫ
�ĺ�ˮ�ںӴ��﷭���ţ������ţ�����һ�����޴�����ѡ�����
�и�կ�ӡ�
LONG
        );

        set("exits", ([
		"east" : __DIR__"bank2",
		"west" : __DIR__"huanghebang1",
		"south" : "/d/forest/field4",
		"north" : __DIR__"weifen",
        ]));

	set("objects", ([
            __DIR__"npc/hou-tonghai" : 1,
	]));

	set("outdoors", "huanghe");
	set("cost", 2);
        setup();
	replace_program(ROOM);
}

