// Code of ShenZhou
// Room: /city/dongdajie2.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����ڶ�����ϣ����ż�ʵ����ʯ����档������ֱͨǮׯ������������Լ
Լ��������Ǯ�ҵ�ײ���������������Ű����ϵ�֮�Ƶ�ҩ�̣��������ҩ��ƽһ
ָҩʦ���Ե���ģ�����ҩ��������������Ч�����Ե����ҩ����ҩ�����ر�ࡣ
����һ�Ҵ����̣�����������һ����(paizi)�����ߵ����ʶ��������ϱߴ����̶�
�������������໥��Ӧ���о����н��ࡣ
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"east" : __DIR__"dongdajie3",
		"south" : __DIR__"datiepu",
		"west" : __DIR__"dongdajie1",
		"north" : __DIR__"yaopu",
	]));
	set("item_desc", ([
                "paizi" : "�չ���ͭ������\n",
        ]));
	set("cost", 1);
	setup();
	replace_program(ROOM);
}

