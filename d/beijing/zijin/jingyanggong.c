//Cracked by Roath
// Room: /d/beijing/zijincheng/jingyanggong.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������֮һ,�����������������Ǿ�ס�ĵط�.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yushufang",
  "west" : __DIR__"gzxd10",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
