//Cracked by Roath
// Room: /d/beijing/zijincheng/tongdaotang.c

inherit ROOM;

void create()
{
	set("short", "ͬ����");
	set("long", @LONG
����һ��շ��䣬��֪����������ʲô�ġ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"xianfugong",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
