// Code of ShenZhou
// Room: /d/xiangyang/shuixingtai.c

inherit ROOM;

void create()
{
	set("short", "ˮ��̨");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"wangcg",
  "westdown" : __DIR__"migonglu",
  "east" : __DIR__"sshuiguan",
]));

	setup();
	replace_program(ROOM);
}
