// Code of ShenZhou
// Room: /d/mingjiao/jxiaochang.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "�����У��");
	set("long", @LONG
�˴��������������У�������������Ľ��ϸ���һ���ɫ��ߴ��죬
ӭ��������졣����������ż���ľ�ܣ���ʮ�˰����֮�⣬����Щ������
��ǹ�Ͷ̸�֮�࣬�����������ǲ�����֮�á�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"tianmoling",
  "east" : __DIR__"shanlu28",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
