// Code of ShenZhou
// Room: /d/newdali/tower4.c

inherit ROOM;

void create()
{
	set("short", "第四层");
	set("long", @LONG
雕有八坐佛，四隅略大，其中东、南两佛面目驳落，容不可辨。
坐佛莲花座皆有梵文佛经。经文尾处刻有“慈济和尚--大理人”字
样。
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"tower5",
  "down" : __DIR__"tower3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
