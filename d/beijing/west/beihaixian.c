//Cracked by Roath
// Room: /d/beijing/west/beihaixian.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"fucuiting",
  "southwest" : __DIR__"beihaiximen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
