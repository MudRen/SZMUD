// Code of ShenZhou
// Room: /d/mingjiao/shanlu20.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "ɽ´");
	set("long", @LONG
һ������ɽͷ���ߵ������ȥ�����Զ����ȥ��֪����������;��
��ɫ�������������У����ֻط���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"shanlu19",
  "southup" : __DIR__"tiehanshan",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
