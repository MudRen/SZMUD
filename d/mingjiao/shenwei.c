// Code of ShenZhou
// Room: /d/mingjiao/shenwei.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
һ���ߴ���Ʒ�����������ǰ���Ʒ����������̽���֡������š���
����һ��������Ʋ������˴����ڹ������ı�´�����ϱ������̺������
У�����á�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"yongdao",
  "northeast" : __DIR__"shandao42",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
