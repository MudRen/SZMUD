// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov5.c

inherit ROOM;

void create()
{
	set("short", "ʯ�̾���");
	set("long", @LONG
�˴�Ϊ��׶״���߲�ʯ�񡣸�Լ����ߣ�����Ϊ�˽��ε���ʯ�����Ͽ�����
���������֮���н�ʯ�����Ǳ���֮���ܣ������ϲ�֮��ʯ������ΪԲ���Σ���
�����������Ϊһ�飬������Ϸ���ɡ�����������̬֮��
LONG);
	set("objects", ([
		__DIR__"npc/sengren" : 2,
		]));
	set("exits", ([
		"south" : __DIR__"minov4",
		"enter" : __DIR__"tower1",
		]));
	set("area", "���ˮ�ٲ�");
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
