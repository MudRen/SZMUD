
// Filename:   /d/jueqinggu/shiliang.c
// Program:    Jiuer
// Date:       Aug 15, 2001


inherit ROOM;

void create()
{
		  set("short","石梁");

		  set("long",@LONG
这里草木渐渐稀少，地面透出光滑而棱角突出的石板，走在上面需
小心翼翼。前面是一座突地拔起的绝壁。
LONG);

	  set("exits",([ 
		"eastdown" : __DIR__"qinghuaao5",
		"northup" : __DIR__"houshan",
		"west" : __DIR__"huowanshi",
			 ]));
	  
	  set("outdoors","jueqing");
	  set("cost",1);

	  setup();	
}

