// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov62.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
һ����ͨ�ϱ��Ĵ�·�����ɴ�������ϱ߽�������Ҫ�ٵ�����·���ϴ�����
��ï�ܣ���Ƭ���ָ���ɽ�룬�˼���ƽ�ƽ̹����·��ֱ�������ű��ߵĴ����
���ϱߵ�ϲ�ݵȳ���
LONG);
	set("exits", ([
		"north" : __DIR__"shqiao",
		"south" : __DIR__"minov63",
		]));
	set("area", "ϲ�ݳ�");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
