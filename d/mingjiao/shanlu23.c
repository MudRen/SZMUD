// Code of ShenZhou
// Room: /d/mingjiao/shanlu23.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "Сɽ·");
	set("long", @LONG
·�߽�����ͺ������Խ��Խ����ǰ����ȥ��һ�Ѷ���ʯ���Ӵ����£�
�˼�ȫ�ޡ���·Ҳ�������С�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"tiekuang",
  "northwest" : __DIR__"tiehanshan",
]));
	set("no_clean_up", 0);
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
