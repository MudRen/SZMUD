// Code of ShenZhou
// Room: /d/mingjiao/qiankun.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "Ǭ����");
	set("long", @LONG
�˴���һ����С��ʯ���Ʒ����Ͽ�һ�ң���׭�塰Ǭ�������֡���
�߿ɼ�һ����������һ���谵�����ȣ����˴˷��������Ͼ͵�������
�������������㳡��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "northup" : __DIR__"shijie77",
  "southdown" : __DIR__"shijie51",
  "west" : __DIR__"zoulang46",
  "east" : __DIR__"dashidian",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
