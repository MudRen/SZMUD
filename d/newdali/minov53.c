// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov53.c

inherit ROOM;

void create()
{
	set("short", "�͵ĵ�");
	set("long", @LONG
������Ǵ�������Ҫ��͵ĵ飬�����ĵ���Ҫ�θ���������Ĳ���ֲ��ڸ�
�������ڶ���ˮ�ȵ����У��͵ĵ����ܶ�ũ��Դ�Ϊ���ģ���·��ͨ�˴�����
�����Ĳ��䡣
LONG);
	set("exits", ([
		"eastup" : __DIR__"minov44",
		"north" : __DIR__"minov54",
		"south" : __DIR__"minov52",
		]));
	set("area", "��ˮ�ذ�");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
