// Code of ShenZhou
// Room: /d/mingjiao/moluo.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "Ħ����");
	set("long", @LONG
һ��ߴ���Ʒ������ڰ�ɽ�Ŀ������ϣ��Ʒ����й�һ���ң�������
�����֡�Ħ���š���������һ���������ߵ�Ħ����񡣹��˴���������
�����������ֵ����̹�������
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "up" : __DIR__"shijie51",
  "southwest" : __DIR__"yongdao",
  "southeast" : __DIR__"yongdao2",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
