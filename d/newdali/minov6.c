// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov6.c

inherit ROOM;

void create()
{
	set("short", "��Ϫ��̶");
	set("long", @LONG
��Ϫ��̶����������ˮ�������ڲ�ɽ��������ʥӦ��֮�������Ͽ���С�ɽ
Ȫ�Ҹ�ӿ��������к����Ϫ��أ�׳�����裬��������ˮ��ʯ������̽��ӣ�
���׳����Ϫ��
LONG);
	set("exits", ([
		"northup" : __DIR__"minov1",
		"southdown" : __DIR__"minov8",
		"eastup" : __DIR__"minov7",
		]));
	set("area", "���ˮ�ٲ�");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
