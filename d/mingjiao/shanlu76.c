// Code of ShenZhou
// Room: /d/mingjiao/shanlu76.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
�ڶ����̵����ڴ˾�������Ⱥ��ӣ�������������һƬ�����֣�
��ʱ����һ����Գ�䡣�ұ������¶��ڣ���һʧ�㣬�����ܾȡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southdown" : __DIR__"shenhuo",
  "west" : __DIR__"milin36",
  "enter" : __DIR__"ldating",
]));
	set("no_clean_up", 0);
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
