// Code of ShenZhou
// Room: /d/xiangyang/huating.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ��ս��Сʤ�����˵о�ʱ���˴������칦�磬�໥��������ͼһʱ֮
�졣��ʱ����ϯ�磬����һЩС�������ڴ�����ɨ���Ա��»����衣�ϱ���һ
���ձڣ��Թ�����������Ϊһʱ֮�澰��Զ�뻨��һӳ��������ɫ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"ysting",
  "south" : __DIR__"lvying",
]));

	setup();
	replace_program(ROOM);
}
