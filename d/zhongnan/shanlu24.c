// Code of ShenZhou
// road: /zhongnan/shanlu24.c
// by sdong 08/98

inherit ROOM;

void create()
{
		  set("short","山路");

		  set("long",@LONG
此段山路是沿着峭壁而开凿出来的，特别崎岖难行。往北向下通往
山脚，东上通往峰顶。
LONG);

		  set("exits",([ "northdown" : __DIR__"shanlu25",
								"eastup" : __DIR__"shanlu23",
						  ])
			  );
	  set("cost",4);
    set("tjjob", 4);
	  set("outdoors", "zhongnan");
	  setup();
	  replace_program(ROOM);
}

