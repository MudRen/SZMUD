//Cracked by Roath
// Room: /d/beijing/west/huanqiu.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"zaichufang2",
  "north" : __DIR__"huangqiongyu",
  "southdown" : __DIR__"shibanlu5",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
