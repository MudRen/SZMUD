// Room: eroad1.c 大道
// By jpei

inherit ROOM;

void create()
{
	set("short", "大道");
	set("long", @LONG
这是一条由青石铺成的大道，西边通向著名的蜀都成都了，向东北走可以
去到湖北。
LONG);
        set("outdoors", "emei");
        set("cost", 1);
	set("exits", ([
		"west" : __DIR__"dadongmen",
		"northeast" : __DIR__"eroad2",
	]));

	setup(); 
	replace_program(ROOM);
}
