// Code of ShenZhou
// Room: /lyddao5.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
������һ����ʯ�̳ɵĴ���ϡ����ܵ���Ұ�Ѿ�����ѩ���ǣ�������ȥ
�����Լ��Ѿ��������ޱ��޼ʵ�ѩԭ�С���������ѩ����Х������������
�����������������ƺ���һ�ƴ�������
LONG
	);

	set("exits", ([
		"south" : __DIR__"lyddao4",
		"north" : __DIR__"muqiao",
	]));

        set("outdoors", "changbai");
        set("cost", 2);

	setup();
	replace_program(ROOM);
}

