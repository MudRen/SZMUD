//Cracked by Roath
// Room: /d/beijing/east/guozijian.c

inherit ROOM;

void create()
{
	set("short", "���Ӽ�");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"zhongtianlou",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
