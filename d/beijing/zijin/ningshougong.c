//Cracked by Roath
// Room: /d/beijing/zijincheng/ningshougong.c

inherit ROOM;

void create()
{
	set("short", "���ٹ�");
	set("long", @LONG
����������ʽ����Ǭ¡�ʵ�׼����̫�ϻ�ʱ�ڴ˹�����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"huangjidian",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
