//Cracked by Roath
// Room: /d/beijing/zijincheng/shiluku.c

inherit ROOM;

void create()
{
	set("short", "ʵ¼��");
	set("long", @LONG
����һ��շ��䣬��֪����������ʲô�ġ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"hongbenku",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
