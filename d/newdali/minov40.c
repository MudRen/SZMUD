// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov40.c

inherit ROOM;

void create()
{
	set("short", "�����в�");
	set("long", @LONG
�����Ǹ������в㣬��¥��һ�������Ǽ�������گ���Ĵ���ŷ��Լ�������
�е��������Ҽһ������������谸����в�����෿����Ϊ���������ݿ�����
��һ����ɴ����
LONG);
	set("objects", ([
		__DIR__"npc/byfangsha.c" : 1,
		__DIR__"obj/fangshaji.c" : 1,
		]));
	set("exits", ([
		"down" : __DIR__"minov39",
		]));
	set("area", "���۲�");
	set("cost", 2);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
