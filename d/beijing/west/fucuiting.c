//Cracked by Roath
// Room: /d/beijing/west/fucuiting.c

inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"yongruiting",
  "south" : __DIR__"beihaixian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
