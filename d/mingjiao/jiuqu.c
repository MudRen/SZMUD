// Code of ShenZhou
// Room: /d/mingjiao/jiuqu.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������ȥ���˴�������Ϊ̨������ʯΪɽ������ˮΪ�ء���������
�����������������������䡣�ٿ�ˮ�У��ɱ����죬Ϻ����Ϸ���������
���飬�����⾰��С԰Сɽ������Ρ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"ceting67",
  "northeast" : __DIR__"jiashan",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
