// Code of ShenZhou
// Room: /d/mingjiao/zhifa.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "ִ����");
	set("long", @LONG
�˴�������ִ��֮������ڴ���������ʨ������������������ͭ����
���̹̽漫�ϣ�����Υ�̹��߱����ط��������������ϲ��Ź���ʥ���죬
��ʾ�������ϡ����ô���һ��ľ�������ϰڻƽ����컢�η����Ҳ����һ
���̼ܣ����ø����̾ߡ�
LONG
	);
set("objects",([
		__DIR__"npc/lengqian" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"shijie77",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
