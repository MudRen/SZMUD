// Code of ShenZhou
// AceP

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
一条的山路蜿蜒穿行在茂密的森林中，向东不远可达大理国的中
心--大理城，西去则进入深山。由于接近大理中心，这条路修整的相
当平整，尽管山势崎岖，行路并不困难。
LONG
	);

	set("exits", ([
		"west" : __DIR__"shanlu2.c",
		"east" : __DIR__"northgate.c",
	]));


	set("cost", 2);
	set("outdoors", "dali");
	setup();
}
