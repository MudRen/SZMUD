// Code of ShenZhou
// Room: /d/mingjiao/daguangchang.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "��㳡");
	set("long", @LONG
�˴������̴�㳡�����﷽Բ�Ŀտ�ƽ�أ�������ש���ϸ����죬ɽ
�紵����������ǻ�������㳡���룬��ʯ����һ����ƽ̨����ʮ���ɵ���
�˸������ƣ���һ����ʥ�����(daqi)������������ҫĿ�����������졣
����ʨ��ӥ��������������ܣ��������������������ơ�
LONG
);
	set("item_desc",([	
		"daqi" : "������һѪɫ���棬�����ҫ���·���������һ�㡣\n",
	]));
	set("exits", ([ /* sizeof() == 6 */
  "northup" : __DIR__"shmen",
  "northwest" : __DIR__"longw",
  "southdown" : __DIR__"shijie77",
  "southeast" : __DIR__"fuw",
  "southwest" : __DIR__"yingw",
  "northeast" : __DIR__"shiw",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
