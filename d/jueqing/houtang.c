//Filename: /d/jueqing/houtang.c 后堂
//Code by Jiuer (08/15/2001)

inherit ROOM;

void create()
{
	set("short","后堂");
	set("long",@LONG
这里是水仙庄的后堂，迎面墙正中央供放着香案，下人们正在忙碌
着，几个家丁从外头跑进来，大厅那边隐隐约约传来一阵阵的格斗声和
喧哗吵闹声。
LONG);

	set("exits", ([
		"east" : __DIR__"changlang5",
		"west" : __DIR__"changlang4",
		"south" : __DIR__"dating",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}