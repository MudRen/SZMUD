// July 31,2000
// Code by April
// /gumu/mudao1.c

inherit ROOM;

void create()
{
        set("short","墓道");

        set("long",@LONG
你进入这阴森森的墓道，也不知道是通到哪儿的。墓外的光只照亮了
几尺墓道，再远一点儿就看不到了。墓道尽头似乎有些人声传来。
LONG);

         set("exits",([ 
               // "west" : __FILE__,
                "north" : __DIR__"dating",
              //  "east" : __FILE__,
                "out" : __DIR__"gumu",
				]));

          set("cost",1);
		  setup();
		  replace_program(ROOM);
}
