// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov67.c

inherit ROOM;

void create()
{
	set("short", "ũ��");
	set("long", @LONG
һСƬ��ɽ���µ������￪�ѳ�����ũ�����Ϫ������ֲ��ˮ����̨����
��ܴ�̶�������ũҵ������ũҵ��ȴ�������Ǹ�Ů�����Ӵ�ר˾���ԺͲ��㡣
LONG);
	set("objects", ([
		__DIR__"npc/tynong" : 1,
		]));
	set("exits", ([
		"south" : __DIR__"minov66",
		]));
	set("area", "�䶨��");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
