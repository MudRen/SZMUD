// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov46.c

inherit ROOM;

void create()
{
	set("short", "����ɽ��");
	set("long", @LONG
�˼���������ɽ���£�����������ɽ�¶��ϣ����ؿ���һ��Ҳ�����֣�����
��ϡ�衣���ĵ���ũҵ������л����ָ��������ڲ�ͬ�ļ��ڸ�����ͬ�����
����฽�������������������˸�����
LONG);
	set("objects", ([
		__DIR__"npc/wynong" : 1,
		]));
	set("exits", ([
		"southwest" : __DIR__"minov47",
		"southeast" : __DIR__"shanlu1",
		"westup" : __DIR__"minov45",
		]));
	set("area", "����ѩɽ");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
