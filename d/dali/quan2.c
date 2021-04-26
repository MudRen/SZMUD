// Code of ShenZhou
// Room: /d/dali/quan2.c

inherit ROOM;

void create()
{
	set("short", "����Ȫ");
	set("long", @LONG
����Ȫ���Եø�������ʪ�󣬴����ĺ�����������˷����㼯�������£�
�����У��������裬��ǧ����ֻ�ʵ�������һ����ʹ�����û��Ž��ء���
�����ں���Ȫ�ϣ�˳���ǵ���������������������һֻҧ��һֻ��β������
��ǧ�ٸ�����������������Ͷʯ��ɢ���������˾�̾����ۡ�
LONG
	);
	set("no_clean_up", 0);
       set("fjing", 1);
	set("outdoors", "dali");
	set("cost", 1);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yuxuguan1",
  "east" : __DIR__"quan1",
]));

	setup();
	replace_program(ROOM);
}
