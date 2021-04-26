//indoor.c zip@hero 2000.1.27 房子内部
#include <ansi.h>
#define ID 3701
inherit ROOM;
void create()
{	set("short","[1;32m风中的花[37;0m");
	set("long",@LONGLONGAGO
我喜欢站在风大的地方
让风沙遮去我的视线
如此就看不见
没有梦的天空
我的心是一片片的花瓣
只想守在你离开的地方
你的承诺
是唯一指引我的方向
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","alan");
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
   call_other("/p/fystreet/board/alan_board","???");
}
#include "indoor_func.c"
