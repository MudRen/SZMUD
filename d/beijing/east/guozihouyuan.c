//Cracked by Roath
// Room: /d/beijing/east/guozihouyuan.c

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"guozihoutang",
  "north" : __DIR__"changshuge",
  "west" : __DIR__"shufang1",
  "east" : __DIR__"shufang2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
