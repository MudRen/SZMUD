// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov48.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����һ����ľ����Ƥ��ɵ�������ӡ��˵صĴ�����Ҫ���¸���������ʵ
�л����ָ������ò�����Ǩ�㣬������ᶼ�ļ�ª��˵�Ƿ��ᣬ������˵������
�񣬲𡢽��������㡣
LONG);
	set("objects", ([
		__DIR__"npc/wykid" : 1,
		]));
	set("exits", ([
		"north" : __DIR__"minov47",
		]));
	set("area", "��ˮ�ذ�");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
