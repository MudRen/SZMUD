//Cracked by Roath
// Room: /d/beijing/zijincheng/yinghuadian.c

inherit ROOM;

void create()
{
	set("short", "Ӣ����");
	set("long", @LONG
   ������.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"shouangong",
  "north" : __DIR__"tongdao8",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
