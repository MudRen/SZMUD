// Code of ShenZhou
// Room: /d/mingjiao/shmen.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "ʥ����");
	set("long", @LONG
һ����ʯ�̳ɵĴ�·��ֱ��ͨ��һ��Ѫ���ǽ�£�·�������������
�����ž��ɡ���ǰ������������ʯ����(guaishou)���������䡣Ѫǽ����
��һ�ߴ���š����������Ƥ���������Ĳ�����ȭͷ��С��ͭ��������
һ�գ��������⡣�������Ը���һС�ţ�������ҹ����롣
LONG
);
	set("item_desc",([
		"guaishou" : "һ�˶�ߵ�ʯ�޵��������צ����ģ����������֮�\n",
	]));
	set("exits", ([ /* sizeof() == 4 */
  "southdown" : __DIR__"daguangchang",
  "west" : __DIR__"guangchang70",
  "enter" : __DIR__"shting",
  "east" : __DIR__"guangchang74",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
