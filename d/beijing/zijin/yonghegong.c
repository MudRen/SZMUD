//Cracked by Roath
// Room: /d/beijing/zijincheng/yonghegong.c

inherit ROOM;

void create()
{
	set("short", "���͹�");
	set("long", @LONG
������֮һ,�����������������Ǿ�ס�ĵط�.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"tongshunzhai",
  "west" : __DIR__"gzxd9",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
