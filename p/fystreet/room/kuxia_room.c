//indoor.c zip@hero 2000.1.27 ?????ڲ?
#include <ansi.h>
#define ID 5001
inherit ROOM;
void create()
{	set("short","[1;36m???? [1;37m& [1;32mС?ײ? [1;33m??[1;35m????[1;34m?Ͼ?[37;0m");
	set("long",@LONGLONGAGO
 ????һ???ս??õĴ?????,?͵???װ???ˡ?
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","kuxia");
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
   call_other("/p/fystreet/board/kuxia_board","???");
}
#include "indoor_func.c"
