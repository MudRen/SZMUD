// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov69.c

inherit ROOM;

void create()
{
	set("short", "��¥");
	set("long", @LONG
һ���׼��̨����¥������ǽ�ڽ������ӣ���������һ�������ε���̨����
�ڼ�������¯�����崫ͳϯ�ض�˯�����������޴�����ǽ���е��죬�����ڳ���
ʯ�Ѽ�̨����޼Ҿߡ�
LONG);
	set("objects", ([
		__DIR__"npc/tykid" : 1,
		]));
	set("exits", ([
		"down" : __DIR__"minov68",
		]));
	set("area", "�䶨��");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
