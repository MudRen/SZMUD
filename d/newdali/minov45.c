// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov45.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ˮ�ӹ��������ů������������ɽ�¿����˲�������˼����ǵ��£�
����������¶��ϣ����ؿ����������֣������ϡ�裬���ĵ���ũҵ��Ϊ���
���л����ָ�������ɽ�ϵ�һЩ��������������������š�
LONG);
	set("objects", ([
		__DIR__"npc/wynong" : 1,
		]));
	set("exits", ([
		"eastdown" : __DIR__"minov46",
		"north" : __DIR__"minov44",	
		]));
	set("area", "����ѩɽ");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
