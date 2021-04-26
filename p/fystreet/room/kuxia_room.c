//indoor.c zip@hero 2000.1.27 ·¿×ÓÄÚ²¿
#include <ansi.h>
#define ID 5001
inherit ROOM;
void create()
{	set("short","[1;36m¿áÏÀ [1;37m& [1;32mĞ¡°×²Ë [1;33mµÄ[1;35mÎÂÇé[1;34mÎÏ¾Ó[37;0m");
	set("long",@LONGLONGAGO
 ÕâÊÇÒ»×ù¸Õ½¨ºÃµÄ´ó·¿×Ó,¾ÍµÈ×Å×°ĞŞÁË¡£
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
