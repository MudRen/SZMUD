// Room: wroad1.c 大道
// By jpei

inherit ROOM;

void create()
{
	set("short", "大道");
	set("long", @LONG
这是一条由青石铺成的大道，东边不远就是著名的蜀都成都了。
LONG);
        set("outdoors", "chengdu");
        set("cost", 1);
	set("exits", ([
		"east" : __DIR__"daximen",
		"west" : __DIR__"wroad2",
	]));

	setup(); 
	replace_program(ROOM);
}
