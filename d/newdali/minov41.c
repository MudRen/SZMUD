// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov41.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
һ��ɽ·���������ï�ܵ����ֺ����಻���Ĵ�ɽ����·���Լ��ɼ�һЩ
����Ĵ�������һƬ��ɽ�������ƣ�ɽ�߰�ѩ�������겻������·������ɽ��
һ����·���������š�
LONG);
	set("exits", ([
		"westup" : __DIR__"minov42",
		"eastdown" : __DIR__"shanlu",
		]));
	set("area", "����ѩɽ");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
