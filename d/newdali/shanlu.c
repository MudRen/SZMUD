// Code of ShenZhou
// Room: /d/dali/shanlu.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
һ����ɽ·���Ѵ�����ï�ܵ�ɭ���У��򶫲�Զ�ɴ�����������--����ǣ�
��ȥ�������ɽ�����ڽӽ��������ģ�����·�������൱ƽ��������ɽ����᫣�
��·�������ѡ�
LONG);
	set("exits", ([
		"westup" : __DIR__"minov41",
		"eastdown" : __DIR__"northgate",
		]));
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
