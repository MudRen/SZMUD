// Code of ShenZhou
// Room: /d/mingjiao/zoulang46.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ���谵�ž������ȣ�����������������Ҳ�ò�������˸��ַ�
���ͼ�Ρ�����������������������������
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"nanxiu",
  "south" : __DIR__"nvxiu",
  "east" : __DIR__"qiankun",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
