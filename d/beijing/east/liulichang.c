//Cracked by Roath
// Room: /d/beijing/east/liulichang.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������·�治������Ҳ�������ۣ���ȴ�Ǿ����������У�
һ����������ȫ����ʿ�ֱʣ�����������ʱ�����ڳ�������ѡ
����ű��伮��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"wangfudajie2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
