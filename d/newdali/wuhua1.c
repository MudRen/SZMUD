// Code of ShenZhou
// Room: /d/dali/wuhua1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������廪¥��ǰ�������쳣������������һ�������ȫ����ʯ�̵أ���
����䣬����������ɶ�����ǧ�ˡ�ʱʱ�ɼ���������������ʳ�������ߡ�
LONG);
	set("objects", ([
		__DIR__"npc/waiter" : 3,
		]));
	set("exits", ([
		"north" : __DIR__"wuhua10.c",
		"west" : __DIR__"wuhua2.c",
		"out" : __DIR__"wuhua.c",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
