// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov12.c

inherit ROOM;

void create()
{
	set("short", "�ּ�С��");
	set("long", @LONG
����һ����ʯ�̳ɵ�С�����������۵�ͨ��ǰ�������������ܵ�����������
��������Ω�����ߵ��·�棬΢�紵����Ҷ��ɳɳ���죬����ֱȥ�ɴ�������
�š�
LONG);
	set("exits", ([
		"southeast" : __DIR__"minov10",
		"westdown" : __DIR__"southgate",
		]));
	set("area", "������");
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
