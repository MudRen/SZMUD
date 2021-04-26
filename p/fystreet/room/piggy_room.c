//indoor.c zip@hero 2000.1.27 ·¿×ÓÄÚ²¿
#include <ansi.h>
#define ID 1401
inherit ROOM;
void create()
{	set("short","[35mĞ¡ÖíµÄ[1;32m¼Ò[37;0m");
	set("long",@LONGLONGAGO
Ò»ÕÅÈáÈíµÄ´ó´²ÉÏ·Å×ÅÒ»¸ösnoopy£¬Ãû×Ö½Ğ°¢¸£¡£ËüºÜ¹ÔµØ×øÔÚ´²ÉÏ¡£
´°×ÓÅÔÓĞÒ»¸ö²£Á§²è¼¸ºÍÁ½°ÑÒÎ×Ó¡£²è¼¸ÉÏ°ÚÁËÒ»ÅèÜÔÀò»¨£¬·¢³öµ­µ­µÄÇåÏã¡£


¶ªµôÊ±¼ä
ÈÃ°®¶¬Ãß
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
