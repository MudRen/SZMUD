// Code of ShenZhou
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "太和城");
	set("long", @LONG
此城是乌夷族的治府，全城巷陌都以石垒成，高丈余，连绵数里
不断。太和不算大城，但人口为数并不少，地理上和军事上是大理城
的北门户，历代大理王朝都在此加固城池，派驻精兵。附近有一些乌
夷部族聚居。此南是一片平原，下十五里便达大理城。
LONG
        );

	set("exits", ([
		"south" : __DIR__"gaten1",
		"north" : __DIR__"nanbei",
		]));

	set("objects", ([
		"/d/dali/npc/dalishibing.c" : 2,
		"/d/dali/npc/wujiang.c" : 1,
		]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}
