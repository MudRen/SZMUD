// Code of ShenZhou
// Room: /d/mingjiao/ceting64.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������̫��Ȼ������Ϊ���ء�����һ��������������ĸ�����ʯ
����ī�ɴ��������ڱڣ���ǽ��ΪһС��������Сɽ�پ�������������ͥ
Ժ����ľ�����м��ò衣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yuanzi65",
  "east" : __DIR__"shting",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
