// Code of ShenZhou
//GU MU FROM SANTA
//cyn.C

inherit ROOM;

void create()
{
	set("short", "重阳练功室");
	set("long", @LONG
这是石室甚是狭窄，正是当年王重阳练习掌法的地方。

LONG
	);
	 set("exits", ([
		"south" : __DIR__"cyc",
	]));
	set("cost", 1);

	setup();
	replace_program(ROOM);
}





