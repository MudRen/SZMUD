// Code of ShenZhou
// Room: /d/newdali/tower7.c

inherit ROOM;

void create()
{
	set("short", "���߲�");
	set("long", @LONG
�����Ǿ����Ķ�����Բ���ζ���������񷡣��������������
������ʿ�ȡ�
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"tower6",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
