// July 31,2000
// Code by April
// /gumu/midao2.c

inherit ROOM;

void create()
{
        set("short", "密道");

        set("long",@LONG
你东转西弯，越走越低。同时脚下渐渐潮湿，心知早已出了古墓，只
是在暗中隐约望去，到处都是岔道，密道中漆黑一片，伸手不见五指。再
走一会儿，道路奇陡，竟是笔直向下，渐渐地你听到流水之声。
LONG);
		
		set("exits",([ "westup" : __DIR__"midao1",
			"eastdown" : __DIR__"midao3",
			]));

		set("cost",5);
		setup();
}

