// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov22.c

inherit ROOM;

void create()
{
	set("short", "�����в�");
	set("long", @LONG
�����Ǹ������в㣬��¥��һ�������Ǽ�������گ���Ĵ���ŷ��Լ�������
�е��������Ҽһ������������谸����в�����෿����Ϊ������
LONG);
	set("objects", ([
		__DIR__"npc/bykid.c" : 1,
		]));
	set("exits", ([
		"down" : __DIR__"minov21",
		]));
	set("area", "��٤��");
	set("cost", 2);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
