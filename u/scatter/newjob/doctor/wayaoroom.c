//Cracked by Kafei
// road: /zhongnan/shulin3.c

inherit ROOM;

void create()
{
        set("short","Ê÷ÁÖ");

        set("long",@LONG
TEST
LONG);

        set("exits",([ "eastdown" : __DIR__"/zhongnan/shulin3.c",
                  
                      ])
           );
          set("cost",2);
          set("outdoors", "quanzhou");

        setup();

}

#include "wayao.h"
