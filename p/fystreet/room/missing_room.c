//indoor.c zip@hero 2000.1.27 房子内部
#include <ansi.h>
#define ID 301
inherit ROOM;
void create()
{	set("short","思念茅庐[37;0m");
	set("long",@LONGLONGAGO
这里就是我的家，人人热爱它！
你不爱它我爱它，到底是谁在爱它？
我到底在写些什么啊！
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","missing");
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
   call_other("/p/fystreet/board/missing_board","???");
}
#include "indoor_func.c"
