// Code of ShenZhou
// Room: /d/mingjiao/ceting67.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ����������м�����Ȼ����Ŀ��ǰ�����ڲ���̫�أ����̫������
�˳߷������ǲ��٣�ȻŨ�����ˣ��������¡��Ҽ�������磬�϶໨��
��ǰ����齣��Լ������壬��ƿ����������ţ�������Ȥ����ǽ��һɽˮ
���ã�������װ���ң���ǰ����ԡ�����¼����Σ����(hengfu)���⣺��
��ɽˮ���ʴ���������������
LONG
);
	set("item_desc",([
		"hengfu" : "�������һ��С�� �������� \n",
]));
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"shting",
  "north" : __DIR__"jiuqu",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
