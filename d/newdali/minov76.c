// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov76.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
���Բ�ר�����ԣ�����������������������һ����ͨ����¥���²�ͨ����
����Ȧ���޲��������Ĺ��һλ̨�ĸ�Ů����ϸ�ĵر�֯������¥����һ��
ľ�ܣ����������ŵ��㣬������ɹ��ɡ�
LONG);
	set("objects", ([
		__DIR__"npc/tywoman" : 1,
		]));
	set("exits", ([
		"east" : __DIR__"minov73",
		]));
	set("area", "������");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
