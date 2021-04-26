
// Filename:   /d/jueqinggu/yutree.c
// Program:    Jiuer
// Date:       Aug 15, 2001


inherit ROOM;

void create()
{
		  set("short","大榆树");

		  set("long",@LONG
绝情谷占地甚广，群山围绕之中，方圆三万余亩。道路曲折，丘屏
壑阻，只见前七八丈处数株大榆树交相覆荫，树底下是一座烧砖瓦的大
窑。
LONG);

	  set("exits",([ 
		"down" : __DIR__"huowanshi",
			 ]));
	  
	  set("objects",([
		  "/d/xingxiu/npc/spider3" : 1,
		   ]));
	  
	  set("outdoors","jueqing");
	  set("cost",1);

	  setup();	
}

