//indoor.c zip@hero 2000.1.27 ·¿×ÓÄÚ²¿
#include <ansi.h>
#define ID 900
inherit ROOM;
void create()
{	set("short","[1;37m ÉñÏÉ¾Æµê[37;0m");
	set("long",@LONGLONGAGO
ÕâÀïÊÇÉñÏÉ¾Æ¼ÒµÄÄÚÕ¬£¬ËÄÃæÇ½ÉÏ°ÚÁĞ×Å´ó´óĞ¡Ğ¡µÄ¾ÆÌ³×Ó£¬Ã¿¸ö¾ÆÌ³ÉÏÌù
×ÅºìÖ½ºÚ×ÖµÄ¡¼¾Æ¡½£¬ÌıËµÕâ¾Æ¾ÍÊÇÔ¶½üÎÅÃûµÄ¡°Å®¶ùºì¡±£¬ÄãµÃ¸øÀÏ°åÄïµã
ºÃ´¦£¬Ò²ĞíËıÒ»¸ßĞËÄÜ¸øÄãµã³¢³¢¡£
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","jiuer");
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
   call_other("/p/fystreet/board/jiuer_board","???");
}
#include "indoor_func.c"
