// Code of ShenZhou
// Room: /d/newdali/tower2.c

inherit ROOM;

void create()
{
	set("short", "第二层");
	set("long", @LONG
为四神坐像，各有表情，衣褶隆起，筋节毕现，肌肉暴起，极富
立体感。
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"tower3",
  "down" : __DIR__"tower1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
