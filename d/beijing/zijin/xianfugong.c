//Cracked by Roath
// Room: /d/beijing/zijincheng/xianfugong.c

inherit ROOM;

void create()
{
	set("short", "�̸���");
	set("long", @LONG
����һ��շ��䣬��֪����������ʲô�ġ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"tongdaotang",
  "east" : __DIR__"chuxiugong",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
