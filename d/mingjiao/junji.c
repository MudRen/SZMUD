// Code of ShenZhou
// Room: /d/mingjiao/junji.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�˴��������������־���֮������ǽ�°�һ��쵻�Ƥ��������������
�����Ϻ�ľ�Ρ��ſ�վ������������ʿ�����������ǳ�������̸����ҹ��
������߻��ܣ��ʳ��˲��������롣
LONG
	);
	set("objects",([
		__DIR__"npc/pengyingyu" : 1,
	]));
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"shijie77",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
