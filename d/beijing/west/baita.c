//Cracked by Roath
// Room: /d/beijing/west/baita.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"puandian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
