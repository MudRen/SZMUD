// Code of ShenZhou
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "大理城北");
	set("long", @LONG
这里是个岔路口。南边就是大理城的北门了，道路从这里分岔，
北去可到太和城，西北通向下关城，也通苍山，是去游苍山和崇圣寺
的必经之路。
LONG
        );

	set("exits", ([
		"north" : __DIR__"taihec",
		"northwest" : __DIR__"esqiao",
		"south" : __DIR__"northgate",
		]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}
