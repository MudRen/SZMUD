//indoor.c zip@hero 2000.1.27 ·¿×ÓÄÚ²¿
#include <ansi.h>
#define ID 200
inherit ROOM;
void create()
{	set("short","[1;32mà½à½[1;36mÍæ¾ß[1;35m°É[37;0m[37;0m");
	set("long",@LONGLONGAGO
 ÕâÊÇÒ»×ù¸Õ½¨ºÃµÄ´ó·¿×Ó,¾ÍµÈ×Å×°ÐÞÁË¡£
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","dudu");
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
   call_other("/p/fystreet/board/dudu_board","???");
}
#include "indoor_func.c"
