//indoor.c zip@hero 2000.1.27 房子内部
#include <ansi.h>
#define ID 3601
inherit ROOM;
void create()
{	set("short","[1;31m火神宫[37;0m");
	set("long",@LONGLONGAGO
乡村小屋式的斜顶房，墙面上有一个大大的车轮，门前的木篱，墙上的褐色木板，在黑色街灯的光线中古朴有味。烈火的宣传词是"给黑夜留一点想象，我有音乐和啤酒。西洋音乐开得小小，给你安静的空间；烈火还有挺好的鸡尾酒和咖啡。
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","sesses");
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
   call_other("/p/fystreet/board/sesses_board","???");
}
#include "indoor_func.c"
