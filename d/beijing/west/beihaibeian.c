//Cracked by Roath
// Room: /d/beijing/west/beihaibeian.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"beihaibeian2",
  "southwest" : __DIR__"beihaixian2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
