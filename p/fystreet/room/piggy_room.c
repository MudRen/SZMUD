//indoor.c zip@hero 2000.1.27 房子内部
#include <ansi.h>
#define ID 1401
inherit ROOM;
void create()
{	set("short","[35m小猪的[1;32m家[37;0m");
	set("long",@LONGLONGAGO
一张柔软的大床上放着一个snoopy，名字叫阿福。它很乖地坐在床上。
窗子旁有一个玻璃茶几和两把椅子。茶几上摆了一盆茉莉花，发出淡淡的清香。


丢掉时间
让爱冬眠
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","piggy");
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
   call_other("/p/fystreet/board/piggy_board","???");
}
#include "indoor_func.c"
