// Code of ShenZhou
// Room: /d/xiangyang/aozhangang.c

inherit ROOM;

void create()
{
	set("short", "��ս��");
	set("long", @LONG
 �㵽��һ��Сɽ֮�ϣ�����Զ����������ˮ�ƺ��������Ľ���Ұ��������
�����д�Ů��ӿ����������ɽ������ȥ���������п�ʯ�������Ͽ���һ�д���
�����ƹ����ɶŸ����Ρ���
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"dufugang",
  "westdown" : __DIR__"dengcheng",
]));

	setup();
	replace_program(ROOM);
}
