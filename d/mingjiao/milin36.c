// Code of ShenZhou
// Room: /d/mingjiao/milin36.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�˴����ɲ��죬ǧ��ٹ֡�������������������ɽ�磬����ȴû��һ
˿��������֦�ϲ�ʱ�м�ֻ���������ȥ����Ϸ��Ȥ����ľ��Ľ����Ǿ�
�������￳����ľ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"xiaolu37",
  "east" : __DIR__"shanlu76",
]));
	set("objects", ([
		__DIR__"obj/pine" : 2,
	]));

	set("cost", 2);

	setup();
//	replace_program(ROOM);
}

