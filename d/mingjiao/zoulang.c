// Code of ShenZhou
// Room: /d/mingjiao/zoulang.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ�������ĵ����ȣ�ż������������ˮ����ڴ�æ�ش��д˵ء�
�������򱱱��Ǻ�ˮ��ĺ��ã���������������������
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"houtang",
  "south" : __DIR__"hdating",
  "east" : __DIR__"cangshui",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
