//indoor.c zip@hero 2000.1.27 ·¿×ÓÄÚ²¿
#include <ansi.h>
#define ID 301
inherit ROOM;
void create()
{	set("short","Ë¼ÄîÃ©Â®[37;0m");
	set("long",@LONGLONGAGO
ÕâÀï¾ÍÊÇÎÒµÄ¼Ò£¬ÈËÈËÈÈ°®Ëü£¡
Äã²»°®ËüÎÒ°®Ëü£¬µ½µ×ÊÇË­ÔÚ°®Ëü£¿
ÎÒµ½µ×ÔÚĞ´Ğ©Ê²Ã´°¡£¡
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
