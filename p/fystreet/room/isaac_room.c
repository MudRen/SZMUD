//indoor.c zip@hero 2000.1.27 �����ڲ�
#include <ansi.h>
#define ID 2401
inherit ROOM;
void create()
{	set("short","[1;31mMuscular Jack [1;34mGymnasium[37;0m");
	set("long",@LONGLONGAGO
A clean basketball court is in front of you. There are many big "MJ" signs all over the place. You can see Big Dog dunking over Junk Yard Dog. You can see Big Ben blocking Kenny Anderson. You can see Big Ticket scoring over Shaq. You can see Big Jer hugging girls. You can see Big Shit smoking.
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","isaac");
       set("no_fight",1);
       set("no_magic",1);
       set("sleep_room",1);
       set("if_bed",1);
       set("NONPC",1);
       set("no_dazuo",1);
       set("no_study",1);
	set("coor/x",40+(ID%2)*20);
	set("coor/y",20+(ID/100)*10);
	set("coor/z",0);
	setup();
   call_other("/p/fystreet/board/isaac_board","???");
}
#include "indoor_func.c"
