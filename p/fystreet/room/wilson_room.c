//indoor.c zip@hero 2000.1.27 房子内部
#include <ansi.h>
#define ID 901
inherit ROOM;
void create()
{	set("short","水果篮[37;0m");
	set("long",@LONGLONGAGO
水果的家,一进来就有一种好舒服好舒服的感觉.
女孩子就千万要小心了,这种感觉很容易让人家入睡,嘿嘿^_^
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","wilson");
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
   call_other("/p/fystreet/board/wilson_board","???");
}
#include "indoor_func.c"
