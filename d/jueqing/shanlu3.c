// /d/jueqing/shanlu3.c
// Jiuer Aug 15, 2001

inherit ROOM;
void create()
{
	set("short","农家");

	set("long",@LONG
这是山脚下的几户农家，屋顶飘出缕缕炊烟，农家主妇们正忙碌着
准备早饭，时不时传来孩子们的打闹声，往东就快到山庄了，往西是上
山的路。
LONG);
	
	set("exits",([
		"east" : __DIR__"shanlu4",
		"northwest" : __DIR__"shanlu2",
		]));
	
	set("outdoors","jueqing");
	setup();
	replace_program(ROOM);
}
