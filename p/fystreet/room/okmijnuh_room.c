//indoor.c zip@hero 2000.1.27 房子内部
#include <ansi.h>
#define ID 1200
inherit ROOM;
void create()
{	set("short","[1;32mbug[1;33m研究室[37;0m");
	set("long",@LONGLONGAGO
一张电脑台占据了狭小的房间里的一大半,办公椅的靠背
后,就是一张小小的沙发床,想来此间主人经常熬通宵
白天临时休息的地方. 
  电脑似乎永远开启,不知道在运行什么程序,经常深夜
传出得意的笑声,想来是个工作狂人吧......
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","okmijnuh");
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
   call_other("/p/fystreet/board/okmijnuh_board","???");
}
#include "indoor_func.c"
