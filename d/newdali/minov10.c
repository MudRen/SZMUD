// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov10.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������к�÷���꣬���Ѱ�ʴ�ݾ��������Ƥ�����ʰ�쵣������ڵأ���
�����죬�罾�������壬���������������Ƭ��������巼Ϯ�ˣ���ֲ֪
�Ժδ����ഫ��Ϊ��÷���ɻ�ȻҲ����������Ǻ���̶��
LONG);
	set("exits", ([
		"northwest" : __DIR__"minov12",
		"southeast" : __DIR__"minov11",
		"north" : __DIR__"minov8",
		]));
	set("area", "������");
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
