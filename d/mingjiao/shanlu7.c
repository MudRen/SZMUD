// Code of ShenZhou
// Room: /d/mingjiao/shanlu7.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����һ������������Сɽ·����������������·��ż�����ż�����
�Ȼ�������ס��������ɽ��������͸�����֣�ֻ������������������
��ɽ�塣
LONG
	);
	set("outdoors", "mingjiao");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"yongdao",
  "west" : __DIR__"qingshilu1",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
