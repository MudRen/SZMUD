// Code of ShenZhou
// Room: /d/dali/dahejie4.c

inherit ROOM;

void create()
{
	set("short", "大和街");
	set("long", @LONG
这是大理城内的主要商贸场所。形形色色的叫卖声在耳边
此起彼伏，连绵不绝。路上车水马龙，各色行人摩肩接踵，热
闹非凡。
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"dahejie3.c",
  "north" : __DIR__"dahejie5.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
