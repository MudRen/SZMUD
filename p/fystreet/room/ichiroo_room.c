//indoor.c zip@hero 2000.1.27 房子内部
#include <ansi.h>
#define ID 2201
inherit ROOM;
void create()
{       set("short",HIW"#51 ICHIROO 棒球练习场"NOR);
	set("long",@LONGLONGAGO
这里是练习场的贵宾室...练完球后可在此小歇片刻 
从透明的玻璃窗看去,可以了望到西雅图水手队练球时的一举一动       
瞧...那身手敏捷的就是铃木一郎
他刚敲出了一支安打
现在正以飞快的脚程向二垒盗去
又一次盗垒成功 
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","ichiroo");
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
   call_other("/p/fystreet/board/ichiroo_board","???");
}
#include "indoor_func.c"
