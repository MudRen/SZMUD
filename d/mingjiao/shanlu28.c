// Code of ShenZhou
// Room: /d/mingjiao/shanlu28.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
��ʯ·�߿���ɽ�ա��ƻ�һƬ�����ض�������ʱʱ�߹��������̵�
�ӣ��еĻ��ﱧ�ż��ѵ����������߶�ȥ��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"jxiaochang",
  "north" : __DIR__"wuqiku",
  "enter" : __DIR__"jneiting",
  "south" : __DIR__"jinlianchang",
]));
	set("no_clean_up", 0);
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
