//Cracked by Roath
// Room: /d/beijing/east/changshuge.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"guozihouyuan",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
