//Cracked by Roath
// Room: /d/beijing/west/yongansi.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"yonganqiao",
  "north" : __DIR__"puandian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
