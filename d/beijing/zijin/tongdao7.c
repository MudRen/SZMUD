//Cracked by Roath
// Room: /d/beijing/zijincheng/tongdao7.c

inherit ROOM;

void create()
{
	set("short", "ͨ��");
	set("long", @LONG
����ͨ������������ŵ�ͨ����һ�������ɸߵ�Χǽ����һ����
��ֲ��������ľ�����ﻨ�������Ŀ�������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"shenwumen",
  "south" : __DIR__"hougongmen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
