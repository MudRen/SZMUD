// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov86.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ǽ����������ģ����Ӳ��󣬾���󲿷��������壬����ȫ��������Ϊ
��������ɽ�ߵغ�������ɽ�ֵ�Ұ�޴��Ƥ��ë���в���Ƥ����������͵���
���˽��ס�����ɽ��������������Ҳ������֮;���ϴ���ɽ��ɵִ�����½��
LONG);
	set("objects", ([
		__DIR__"npc/wylieren1.c" : 1,
		__DIR__"npc/phshang.c" : 1,
		]));
	set("exits", ([
		"southup" : __DIR__"minov84",
		"north" : __DIR__"minov87",
		]));
	set("area", "������");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
