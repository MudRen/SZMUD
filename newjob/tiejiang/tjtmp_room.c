// tjtmp_room.c 样品铁匠工作场所  妓珇臟初┮  
// snowlf by 2001.10.24
 
#include <room.h>
#include <ansi.h>

inherit ROOM;

void reset();
int valid_leave();

void create()
{
        set("short","样品"+HIB+"铁匠工作场所"NOR);
        set("long","这里是多职业系统第一组做的样品"+HIB+"铁匠工作场所"+NOR+"。建在一个依山傍水
的小山脚下，先前刚刚建好的时候，还只是一间空空的房子，里面什么也
没有，但是现在第一组的人员已经找了不少东西放进来了！
");

        
        set("exits", ([

		"out" : "/d/quanzhou/datiepu",

        ]));


/*
      	set("valid_startroom",1);
        set("no_clean_up",0);
        set("no_fight",0);
        set("no_steal",1);
*/
        set("objects",([
               __DIR__"npc/tjtmp_npc":1,
               __DIR__"obj/datiechui":1,
               __DIR__"obj/gangqian":1,
               __DIR__"obj/gao":1,
               
    	   ]));     
        setup();

}
