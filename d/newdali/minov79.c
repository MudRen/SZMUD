// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov79.c

inherit ROOM;

void create()
{
	set("short", "����¥");
	set("long", @LONG
����һ����ͨ��ʽ��̨����¥������³�������ģ�������������¥��ռ�ع�
��ö࣬Ҳ�ر�ߴ��������㣬�������Ჿ�ļ�����ݡ��˴��²�Ҳ��������
��ɨ�øɸɾ�������������ֱͨ�ϲ�
LONG);
	set("exits", ([
		"south" : __DIR__"minov78",
		"up" : __DIR__"minov80",
		]));
	set("area", "³����");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
