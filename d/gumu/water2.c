// July 31,2000
// Code by April
// /gumu/water2.c

inherit ROOM;

void create()
{
        set("short", "地下水道");

        set("long",@LONG
在地下潜流中,你只觉得水声轰轰,身子不由自主的被强大的水流向前
推送.
LONG);

        set("exits",([ "west" : __DIR__"water1",
                        "eastup" : "/d/zhongnan/dong",

                      ])
           );
	  set("cost",5);

	  setup();
}


