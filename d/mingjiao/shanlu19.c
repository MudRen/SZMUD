// Code of ShenZhou
// Room: /d/mingjiao/shanlu19.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
��ֻ�۷��ڴҴҵ�æµ�ţ�����СС��ɽ·�����˼����������峿��
�������������ϵ�ˮ��ɢ���Ѥ����������ż��һֻҰ�ôڹ����ڲ�����
�µ����ļǺۡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northwest" : __DIR__"shanya21",
  "east" : __DIR__"shanlu20",
  "southdown" : __DIR__"yongdao2",
]));
	set("no_clean_up", 0);
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
