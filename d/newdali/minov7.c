// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov7.c

inherit ROOM;

void create()
{
	set("short", "�̼�ɽ��");
	set("long", @LONG
�̼�ɽ���ڵ�ص������ϣ����ض��Ǹ�ˮ������ɽ�Ƹ������ƣ�ɽ�����繫
������ɽ��ľ�Դ����Ρ��˴����Ǽ������Ѵ��ƶˣ��������һƬ��������ʤ
�ա�ɽ��������������ݡ�����������ɽ֮·��
LONG);
	set("objects", ([
		__DIR__"npc/youke1.c" : 1,
		]));
	set("exits", ([
		"westdown" : __DIR__"minov6",
		"eastdown" : __DIR__"minov19",
		]));
	set("area", "���ˮ�ٲ�");
	set("cost", 5);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
