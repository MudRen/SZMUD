// Code of ShenZhou
// Room: /d/mingjiao/guangchang74.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "�㳡");
	set("long", @LONG
�˴���һ��С�㳡��ֻ��һ�Ӷӽ�������ȥȥ�����Ÿ��ַ�ɫ���е�
Я������ǹ�������ȵȱ������������˽ý�����̬ׯ�ء��㳡���󣬹�ͨ
���ϱ����ߵķ��֡������Ŵ�����
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"shmen",
  "south" : __DIR__"lei",
  "north" : __DIR__"feng",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
