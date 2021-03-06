// Code of ShenZhou
// Room: /d/dali/hongshengt.c

inherit ROOM;

void create()
{
	set("short", "宏圣寺塔");
	set("long", @LONG
宏圣寺塔又名“一塔”，屹立于苍山之麓，面向洱海，
为云南著名唐塔之一。宏圣寺塔为四方形空心砖石塔，塔身
各层之间用砖砌出跌涩椽，使其四角飞翘。整个塔身轮廓呈
抛物线，优美流畅。
LONG
	);
	set("no_clean_up", 0);
	set("cost", 2);
	set("exits", ([ /* sizeof() == 3 */
  "enter" : __DIR__"hongtj.c",
//  "southup" : __DIR__"chhill1.c",
 "northup" : __DIR__"tianls1.c",
  "west" : __DIR__"cangshan",
]));

	setup();
	replace_program(ROOM);
}
