//indoor.c zip@hero 2000.1.27 房子内部
#include <ansi.h>
#define ID 1600
inherit ROOM;
void create()
{	set("short","如意[37;0m");
	set("long",@LONGLONGAGO
    这是一座临湖的小榭。依榭观湖，只见荷花满湖，茭荷深处，香远益清。
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","xinger");
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
   call_other("/p/fystreet/board/xinger_board","???");
}
#include "indoor_func.c"
