// Code of ShenZhou
// Room: /d/mingjiao/liangong.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�Ҽ��һ��¯�ͼ������棬����������������������ڣ�û��һ˿
������ż�����������������ľ����������ĵ����ǳ��������ڴ�������
����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"shijie51",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
