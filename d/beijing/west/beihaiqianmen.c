//Cracked by Roath
// Room: /d/beijing/west/beihaiqianmen.c

inherit ROOM;

void create()
{
	set("short", "����ǰ��");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zhonghaibeian",
  "northwest" : __DIR__"chengguangdian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
