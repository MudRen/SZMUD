// Code of ShenZhou
// shaqiu.c
// maco

inherit ROOM;

void create()
{
    int i;
	set("short", "ɳ��");
	set("long", @LONG
������һ���޼ʵ�ɳĮ���Ĺ�ãã������ɳ���ϱߵ�ɳ���
�ֳ�ϡϡ��������ݡ�
LONG
	);

	set("exits", ([
		"east" : __DIR__"shamo1",
		"west" : __DIR__"shamo2",
		"south" : __DIR__"luzhou2",
		"north" : __DIR__"shamo4",
	]));
	set("outdoors","xingxiu");
	set("cost", 2);
	setup();
	replace_program(ROOM);
}

