//Cracked by Roath
// Room: /d/beijing/kangqin/zhoulang7.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"houtang",
  "east" : __DIR__"moongate",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
