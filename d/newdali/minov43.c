// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov43.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
һ��ɽ·��������ï�ܵ����֣����������಻���Ĵ�ɽ����·���Լ��ɼ�
һЩ����Ĵ���ɽ·���������š�
LONG);
	set("exits", ([
		"northup" : __DIR__"minov42",
		"southwest" : __DIR__"shanlu1",
		]));
	set("area", "����ѩɽ");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
