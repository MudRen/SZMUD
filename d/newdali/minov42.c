// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov42.c

inherit ROOM;

void create()
{
	set("short", "����ѩɽ");
	set("long", @LONG
����һƬ��ѩɽ֮�У��˵�ֻ�ǰ�ɽ����ȴ�Ѿ���ѩ����������̹��ˡ�
��ͷ��ȥ�����׵ķ���������У����Ҳ�����ر����䡣�ɴ����ϵ�ɽ��������
�����ټ���ֻ���°��ɵ�ɽ��������ľ�������������޺��е������ˡ��򶫲�Զ
��һ������������ڳ�ɽ����֮������һƬ�ȵء�
LONG);
	set("exits", ([
		"southdown" : __DIR__"minov43",
		"westdown" : __DIR__"minov44",
		"eastdown" : __DIR__"minov41",
		]));
	set("area", "����ѩɽ");
	set("cost", 5);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
