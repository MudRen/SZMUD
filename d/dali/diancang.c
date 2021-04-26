// Code of ShenZhou
// AceP

inherit ROOM;

void create()
{
	set("short", "点苍山");
	set("long", @LONG
点苍山是大理的名山，山势雄壮，高耸入云。这里有条山路通往北面。
LONG
	);

	set("exits", ([
		"southeast" : __DIR__"shanlu1.c",
		"north" : __DIR__"tlsgate.c",
	]));


	set("cost", 2);
	set("outdoors", "dali");
	setup();
}
