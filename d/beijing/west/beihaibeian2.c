//Cracked by Roath
// Room: /d/beijing/west/beihaibeian2.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"beihaidongan",
  "west" : __DIR__"beihaibeian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
