//Cracked by Roath
// Room: /d/beijing/zijincheng/tongdao8.c

inherit ROOM;

void create()
{
	set("short", "ͨ��");
	set("long", @LONG
����ͨ������������ŵ�ͨ����һ�������ɸߵ�Χ
ǽ����һ������ֲ��������ľ�����ﻨ�������Ŀ�������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"yinghuadian",
  "east" : __DIR__"shenwumen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
