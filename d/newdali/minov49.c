// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov49.c

inherit ROOM;

void create()
{
	set("short", "��ͷ��");
	set("long", @LONG
��ͷ�����������Ĳ��䣬�͸���������һ����Ҳ�������ġ�����ɽ�����ܣ�
����������ʽ�ɽ����������·ɥ������ɽ������������˵ȴ�Ǿ۱��裬ɽ��
Ұ�������ζ��
LONG);
	set("objects", ([
		__DIR__"npc/wylieren" : 1,
		]));
	set("exits", ([
		"southeast" : __DIR__"minov47",
		"westup" : __DIR__"minov50",
		"north" : __DIR__"minov52",
		]));
	set("area", "��ˮ�ذ�");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
