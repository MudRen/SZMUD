//Cracked by Roath
// Room: /d/beijing/kangqin/xixiangfang.c

inherit ROOM;

void create()
{
	set("short", "���᷿");
	set("long", @LONG
����һ��ܿ��ķ��䡣��������һ�ſ����������Ž�������
���������ӣ��������һյ�͵ơ�����ܸɾ�����Ȼ�������˴�ɨ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"tingyuan",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
