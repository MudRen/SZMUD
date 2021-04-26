// Code of ShenZhou
// AceP

inherit ROOM;

void create()
{
	set("short", "茶花山");
	set("long", @LONG
你站在一座小山西面脚下，大理盛产茶花，好品种的茶花遍
地生长，东面的这片小山林也长满了好茶。西边不远就是大理城
的北门了。
LONG
	);

	set("exits", ([
		"west" : __DIR__"northgate.c",
		"eastup" : __DIR__"chhill1.c",
		]));

	set("cost", 2);
	set("outdoors", "dali");
	setup();
}
