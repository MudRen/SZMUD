// Code of ShenZhou
// Room: /d/mingjiao/tdating.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "���������");
	set("long", @LONG
�˼䲻����󣬲���֮�н���һ��ѹ��֮�⡣����վ�����ź������
�ӣ����Ż��»ƽ����г��貢����������ȴ��һ��˵���������ϡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"txiaochang",
  "north" : __DIR__"tneitang",
]));
	set("objects",([
		__DIR__"npc/yanyuan" : 1,
	]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
