// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov59.c

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
������һƬï�ܵ�ɽ���У�ʱ���з������޺�����������ּ�������ϱ���
�Ĳ�����Ĵ��񾭳��������ԡ�ɽ�ֱ��治Զ����¡¡ˮ���������д��������
�ϱ���һƬ���ݵĺӹ���أ��������̡�
LONG);
	set("objects", ([
		__DIR__"npc/wylieren" : 1,
		]));
	set("exits", ([
		"north" : __DIR__"minov60",
		"southdown" : __DIR__"minov58",
		]));
	set("area", "��³��");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
