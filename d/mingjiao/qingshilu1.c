// Code of ShenZhou
// Room: /d/mingjiao/qingshilu1.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
С������ʯ�̳ɣ���������ɨ��Ȼɽ���磬���Ըɾ������̰߱س�
��������Ϊ�֣����³�����ɫҰ���������׷ɣ�����ʱ�١�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"shanlu7",
  "northwest" : __DIR__"qingyun",
  "southdown" : __DIR__"shanjiao1",
]));
	set("no_clean_up", 0);
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
