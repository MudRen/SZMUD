//Cracked by Roath
// Room: /d/beijing/west/hubianxiaodao4.c

inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"nanhaidongan",
  "north" : __DIR__"zhonghaidongan",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
