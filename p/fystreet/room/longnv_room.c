//indoor.c zip@hero 2000.1.27 房子内部
#include <ansi.h>
#define ID 300
inherit ROOM;
void create()
{	set("short","[35m绝情谷断肠崖[37;0m");
	set("long",@LONGLONGAGO
 这里是龙女的小屋

不再回头不再是古老的辰光
也不只是那些个夜晚的星群和月亮
尽管每个清晨仍然会开窗探望 
每个夏季仍然会有茉莉的清香

LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","longnv");
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
	set("objects", ([__DIR__"obj/cabinet" : 1,]),);
	setup();
   call_other("/p/fystreet/board/longnv_board","???");
}
#include "indoor_func.c"
