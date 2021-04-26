// Room: eroad3.c 大道
// By jpei

inherit ROOM;

void create()
{
	set("short", "大道");
	set("long", @LONG
这是一条由青石铺成的大道，西南边通向四川的中部，东面不远处就是川
鄂交界的地方了。
LONG);
        set("outdoors", "emei");
        set("cost", 1);
	set("exits", ([
		"east" : __DIR__"eroad4",
		"southwest" : __DIR__"eroad2",
	]));

	setup(); 
	replace_program(ROOM);
}
