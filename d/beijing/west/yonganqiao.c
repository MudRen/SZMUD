//Cracked by Roath
// Room: /d/beijing/west/yonganqiao.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"chengguangdian",
  "north" : __DIR__"yongansi",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
