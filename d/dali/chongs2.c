// Code of ShenZhou
// Room: /d/dali/chongs2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����������������������̲����죬�׷���㡣���е���
����֯Ů���еĽ������ڱ�֯��һ����̵Ľ��С�����������
����������˿˿�������ߣ��Զ�ʤ�������۵ס�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"chongs1.c",
]));
	set("no_clean_up", 0);
	set("cost", 3);
	setup();
	replace_program(ROOM);
}
