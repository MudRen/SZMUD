// Code of ShenZhou
// Room: /d/mingjiao/shangang.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
���ϳ������۲ݣ���Զ����һȺɽ�����ڳԲݡ�������һ͹�壬��ɽ
ʯ��Ϊ��ɫ����ĺʱ�֣��ر���Ŀ��ɽ���ǳ���Ϊ���塣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"tianmoling",
  "southwest" : __DIR__"shanya21",
  "northup"	: __DIR__"shenhuo",	
]));
	set("no_clean_up", 0);
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
