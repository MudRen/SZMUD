// Code of ShenZhou
// Room: /d/mingjiao/hqku.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�˴�ʮ�ֻ谵�����쳣����������ߣ���Լ�ɼ�����������޷���
һЩľͰ���������ŵ�һ�����ǵĳ�����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"szchang",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
