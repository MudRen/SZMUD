// Code of ShenZhou
// Room: /d/mingjiao/shanmentongdao.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "ɽ��ͨ��");
	set("long", @LONG
����һ��������ɽ��ͨ�������¶����������졣��·����ʯ�̳ɣ���
ʱ�����������������������������Ǹ��ʵ�ɽ�ң����ù������̶��ϡ�
��ĿԶ����ֻ������ɽ�屻�����������������С�
LONG
	);
	set("outdoors", "mingjiao");
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"shijie2",
  "northwest" : __DIR__"shijie1",
  "southdown" : __DIR__"damen",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
