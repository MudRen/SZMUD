//Cracked by Roath
// Room: /d/beijing/west/shibanlu4.c

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"beitianmen",
  "southup" : __DIR__"qiniandian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
