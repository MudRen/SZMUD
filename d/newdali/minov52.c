// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov52.c

inherit ROOM;

void create()
{
	set("short", "��ˮ�ذ�");
	set("long", @LONG
һ����·������ˮ�ݹ�ȵ��ϱ���������ˮ������ȥ���������³�ˢ�Ź���
��أ��������ѩɽ������ĸ���ɽ�Ը��ʱ��ա���·��ͨ�˹����Ĵ���͵ĵ飬
������������С���䡣
LONG);
	set("exits", ([
		"north" : __DIR__"minov53",
		"south" : __DIR__"minov49",
		]));
	set("area", "��ˮ�ذ�");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
