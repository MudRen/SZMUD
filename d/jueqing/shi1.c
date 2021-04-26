// /d/jueqing/shi1.c  小室
// By jiuer

inherit ROOM;

void create()
{
	set("short","小室");
	set("long",@LONG 
只见屋中陈设简陋，但洁净异常，堂上只一桌一几，此外便无别物，
桌几放置的方位你却熟悉之极，竟与古墓石室中的桌椅一模一样。向右
侧转去，是间小室。
LONG);
	
	set("exits",([ 
		"east" : __DIR__"shi2",
		"out" : __DIR__"maowu",
		]));
	
	set("objects", ([
		"/d/jueqing/obj/fish" : 1,
		]));
	set("resource/water", 1);	
	set("cost",1);
	setup();
	replace_program(ROOM);
}
