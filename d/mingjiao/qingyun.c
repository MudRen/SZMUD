// Code of ShenZhou
// Room: /d/mingjiao/qingyun.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "���Ʒ�");
	set("long", @LONG
������ǹ�����ɽ´��һ���߷壬��˴��������ߣ������������ƣ�
�������Ʒ塣����һ��ʯ��ͨ��һ��ɽͤ���˴��������أ����˾�����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"hst",
  "southeast" : __DIR__"qingshilu1",
]));
	set("no_clean_up", 0);
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
