// Code of ShenZhou
// Room: /d/mingjiao/xiaochang.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "У��");
	set("long", @LONG
�˴��������̺�ˮ��У�������������Ľ��ϸ���һ����ߴ��죬ӭ
��������졣����������ż���ľ�ܣ���ʮ�˰����֮�⣬����Щ��Ͳ��
����ˮ������ǲ�����֮�á�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"hst",
  "enter" : __DIR__"hdating",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
