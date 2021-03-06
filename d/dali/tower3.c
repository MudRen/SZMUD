// Code of ShenZhou
// Room: /d/newdali/tower3.c

inherit ROOM;

void create()
{
	set("short", "第三层");
	set("long", @LONG
雕绕绫坐像四座，坐像间之四面各雕佛及菩萨一组。识者谓北面
多臂观音，南面为地藏菩萨。合神佛面目和蔼，雕刻精细，造形优美。
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"tower4",
  "down" : __DIR__"tower2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
