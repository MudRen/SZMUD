// Code of ShenZhou
// Room: /d/mingjiao/shijie51.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����Ȼ��ʯ��ż�ܿ��������ӡ�ǡ�����ֲ���˴����ܶ�������
�����ҡ���һ��С���������ߵ����У�̽�׹�ȥ���Ʋ����ܳ�������������
��Ϣ��Ȼ������ͤͤ��������ֻɽȸС�䣬������ݣ������ˬ��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "northup" : __DIR__"qiankun",
  "west" : __DIR__"liangong",
  "down" : __DIR__"moluo",
  "east" : __DIR__"shuyuan",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
