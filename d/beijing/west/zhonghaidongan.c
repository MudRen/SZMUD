//Cracked by Roath
// Room: /d/beijing/west/zhonghaidongan.c

inherit ROOM;

void create()
{
	set("short", "�к�����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"hubianxiaodao4",
  "north" : __DIR__"hubianxiaodao2",
  "east" : __DIR__"shulin1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
