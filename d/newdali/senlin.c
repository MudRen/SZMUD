// Code of ShenZhou
// Room: /d/dali/senlin.c

inherit ROOM;

void create()
{
	set("short", "��ɭ��");
	set("long", @LONG
��ȥ��������ɽ���ʹ�ɭ�֣������Ѿ���ľï���˼������ˣ������Ǵ���
����ԭ�Ĺٵ���·��
LONG);
	set("exits", ([
		"southdown" : __DIR__"minov15",
		"north" : __DIR__"senlin1",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
