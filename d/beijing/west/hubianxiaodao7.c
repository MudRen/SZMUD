//Cracked by Roath
// Room: /d/beijing/west/hubianxiaodao7.c

inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"bridge",
  "west" : __DIR__"chengguangdian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
