//indoor.c zip@hero 2000.1.27 房子内部
#include <ansi.h>
#define ID 1500
inherit ROOM;
void create()
{	set("short","象牙白塔[37;0m");
	set("long",@LONGLONGAGO
　　长年不见天日，青苔就肆无忌惮地到处生长，腐臭气味直冲鼻端，异常森寒的温度，在 ;地上结成一层又一层的厚霜，不时又转为白烟，冉冉上冒，恶劣的环境，就是一个极度险难 ;的地方。 ;
;　　
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","szlr");
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
   call_other("/p/fystreet/board/szlr_board","???");
}
#include "indoor_func.c"
