// Code of ShenZhou
// Room: /d/dali/wuhua8.c

#include <ansi.h>
#include <dbase.h>

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
这是一条长长的走廊，通向各个客人的寝室。到了二楼，毛毡已经
换成纯白，两侧木壁上或刻有花鸟鱼虫，或挂了些许时人的字画，每隔
七八步，就有一处香台，缕缕青烟从铜鹤嘴里游出，闻之精神一振。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"wuhua3.c",
  "enter" : __DIR__"wuhua4.c",
]));
	set("no_clean_up", 0);
set("cost", 1);
	setup();
}
