// Code of ShenZhou
// Room: /d/dali/tower7.c

inherit ROOM;

void create()
{
	set("short", "���߲�");
	set("long", @LONG
�����Ǿ����Ķ�����Բ���ζ���������񷡣�������������𣬷�����ʿ�ȡ�
LONG);
	set("exits", ([
		"down" : __DIR__"tower6",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
