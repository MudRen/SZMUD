//Cracked by Roath
// Room: /d/beijing/kangqin/tingyuan.c

inherit ROOM;

void create()
{
	set("short", "ǰԺ");
	set("long", @LONG
����������ǰԺ��һ��Ӱ�ڽ�Ժ�ӷֳ����롣����������һ
���᷿������������ס�ĵط���
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"zhongmen",
  "west" : __DIR__"xixiangfang",
  "north" : __DIR__"door",
  "east" : __DIR__"dongxiangfang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
