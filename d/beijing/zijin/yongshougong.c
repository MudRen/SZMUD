//Cracked by Roath
// Room: /d/beijing/zijincheng/yongshougong.c

inherit ROOM;

void create()
{
	set("short", "���ٹ�");
	set("long", @LONG
�����������������Ǿ�ס�ĵط�.
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"yangxindian",
  "west" : __DIR__"taijidian",
  "east" : __DIR__"tongdao1",
]));
	set("no_clean_up", 0);
	set("exit", "e");

	setup();
	replace_program(ROOM);
}
