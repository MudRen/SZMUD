// Code of ShenZhou
// Room: /d/mingjiao/shijie77.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
�˴�ʯ��������Ǭ�����ʹ�㳡������ȥ������Լ����������
ʯ���䲻�ܳ��������������������֡��ɴ����Ͽɵ���㳡�����������
������ִ����������
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northup" : __DIR__"daguangchang",
  "southdown" : __DIR__"qiankun",
  "northeast" : __DIR__"zhifa",
  "northwest" : __DIR__"junji",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
