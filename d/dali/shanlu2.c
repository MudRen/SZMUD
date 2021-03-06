// Code of ShenZhou
// AceP

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
一条山路，四面皆是茂密的树林和延绵不绝的大山，道路两旁间
或可见一些夷族的村镇，西面一片高山高耸入云，山颠白雪皑皑终年
不化。正路向西上山，一条岔路向南蜿蜒着。
LONG
	);

	set("exits", ([
		"east" : __DIR__"shanlu1.c",
		"westup" : __DIR__"minov49.c",
		"south" : __DIR__"shanlu3.c",
		]));


	set("cost", 2);
	set("outdoors", "dali");
	setup();
}
