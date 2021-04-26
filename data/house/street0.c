#include <ansi.h>
inherit ROOM;
void create()
{	set("short",HIG"风云天骄门"NOR);
	set("long",HIC"
                     ____________
                ____/            \\____
         ___   /    ^ "+HIY"云  天  骄"+HIC" ^    \\   ___
        /^^^**^^ _"+HIY"风              门"+HIC"_ ^^**^^^\\
       /        /      _------_      \\        \\"NOR+"

    这是一座古老而神圣的大理石门，大约建于百年前。门上斑斑点点，
风化不堪。传说中是玉皇大帝临凡佳奖天下儿女英雄的地方，凡是被佳
奖的英雄都成为不死之身。
      进去就是风云街了。往西是风云商场，往东则到房管处。\n"  
	);
	set("exits",([
        "south" : "/d/fy/ecloud5",
	"north": __DIR__"street1",
	"east" : __DIR__"masteroom",
	"west" : __DIR__"shop",
		]));
	set("coor/x",50);
	set("coor/y",20);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{ object ob;
  if(dir=="south"&&objectp(ob=present("room builder",this_object())))
    if(ob->query("owner")==me->query("id"))
      { message_vision("$N说道：这就走么？\n",ob);
        destruct(ob);}
return 1;}
   
