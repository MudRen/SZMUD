//Cracked by Roath
// Room: /d/beijing/west/yongruiting.c

inherit ROOM;

void create()
{
	set("short", "ӿ��ͤ");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"longzheting",
  "southwest" : __DIR__"fucuiting",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
