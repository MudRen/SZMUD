// Code of ShenZhou
// Room: /city/xiaotulu.c
// YZC 1996/11/13 

inherit ROOM;

void create()
{
	set("short", "С��·");
	set("long", @LONG
����һ��û��ʯ��Ļ���С·�������������˺��٣�ֻ�м����ϼ���������
����⾭����·�Լ���С�к����ں�һֻҰ����ˣ����������ͦ�µ�ũ��С�ݣ�
�����ǽ���û��ã�������С�ݵ����˻��ϸ�ԣ�����������ƾɵ�С�����ϱ�
�����Ͻ��ˡ�
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"east" : __DIR__"minwu2",
		"southwest" : __DIR__"xiangnanjie",
		"southeast" : __DIR__ "xiaomiao",
	]));

        set("objects", ([
		__DIR__"npc/boy" : 2,
		__DIR__"npc/dog" : 1,
        ]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

