// Jiuer Aug 15, 2001
inherit ROOM;
void create()
{
	set("short","山脚下");

	set("long",@LONG
山路渐渐变的平坦宽阔起来，走起来也不显疲惫，东边已经依稀可
见山庄的大石屋了，你不由的加快了脚步。
LONG);
	
	set("exits",([
		"east" : __DIR__"stoneroad",
		"west" : __DIR__"shanlu3",
		]));
	set("cost",1);
	set("outdoors","jueqing");
	setup();
	replace_program(ROOM);
}