//Cracked by Roath
// Room: /d/beijing/west/shibanlu5.c

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"nantianmen",
  "northup" : __DIR__"huanqiu",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
