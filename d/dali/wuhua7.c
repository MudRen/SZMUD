// Code of ShenZhou
// Room: /d/dali/wuhua7.c

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
这是一条长长的走廊，通向各个客人的寝室。到了二楼，毛
毡已经换成纯白，两侧木壁上或刻有花鸟鱼虫，或挂了些许时人
的字画，每隔七八步，就有一处香台，缕缕青烟从铜鹤嘴里游出，
闻之精神一振。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"wuhua6.c",
  "enter" : __DIR__"wuhua9.c",
]));
	set("no_clean_up", 0);
set("cost",1);
	setup();
	replace_program(ROOM);
}
