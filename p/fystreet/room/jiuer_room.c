//indoor.c zip@hero 2000.1.27 房子内部
#include <ansi.h>
#define ID 900
inherit ROOM;
void create()
{	set("short","[1;37m 神仙酒店[37;0m");
	set("long",@LONGLONGAGO
这里是神仙酒家的内宅，四面墙上摆列着大大小小的酒坛子，每个酒坛上贴
着红纸黑字的〖酒〗，听说这酒就是远近闻名的“女儿红”，你得给老板娘点
好处，也许她一高兴能给你点尝尝。
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","jiuer");
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
   call_other("/p/fystreet/board/jiuer_board","???");
}
#include "indoor_func.c"
