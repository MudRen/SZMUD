//Cracked by Roath
// Room: /d/beijing/west/fuyoujie.c

inherit ROOM;

void create()
{
	set("short", "���ҽ�");
	set("long", @LONG
����һ��Ƨ������ʯ��֣�·��ֻ���������伸�����ˣ�������
��ֵ����־���������ԶԶ������������һ�������������һ����
ͬ����Լ��������֮����
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"lingjing",
  "north" : __DIR__"fuyoujie2",
  "south" : __DIR__"fuyoujie3",
  "east" : __DIR__"zhonghaixian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
