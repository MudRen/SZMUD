// July 31,2000
// Code by April
// /gumu/midao1.c

inherit ROOM;

void create()
{
        set("short", "密道");

        set("long",@LONG
密道中漆黑一片，伸手不见五指。但只觉越走越低，湿气也越来越重。
往上是一个小洞。往东则是黑黑的一片。
LONG);

          set("exits",([ "up" : __DIR__"mudao13",
                        "eastdown" : __DIR__"midao2", ])
                          );
          set("cost",3);

          setup();
}
