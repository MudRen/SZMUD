// Code of ShenZhou
// Room: /d/dali/tusi3.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������������裬���³����ŵ����桢ì��ꪵȱ����������Ĵ�¥���£�
������ʵ�����ÿ���ǰ�����һ�������������������Ϣ��
LONG);
	set("objects", ([
		__DIR__"npc/datusi" : 1,
		__DIR__"npc/touren" : 2,
		]));
	set("exits", ([
		"north" : __DIR__"tusi4",
		"east" : __DIR__"tusi2",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
