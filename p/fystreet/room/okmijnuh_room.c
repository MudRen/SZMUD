//indoor.c zip@hero 2000.1.27 ·¿×ÓÄÚ²¿
#include <ansi.h>
#define ID 1200
inherit ROOM;
void create()
{	set("short","[1;32mbug[1;33mÑĞ¾¿ÊÒ[37;0m");
	set("long",@LONGLONGAGO
Ò»ÕÅµçÄÔÌ¨Õ¼¾İÁËÏÁĞ¡µÄ·¿¼äÀïµÄÒ»´ó°ë,°ì¹«ÒÎµÄ¿¿±³
ºó,¾ÍÊÇÒ»ÕÅĞ¡Ğ¡µÄÉ³·¢´²,ÏëÀ´´Ë¼äÖ÷ÈË¾­³£°¾Í¨Ïü
°×ÌìÁÙÊ±ĞİÏ¢µÄµØ·½. 
  µçÄÔËÆºõÓÀÔ¶¿ªÆô,²»ÖªµÀÔÚÔËĞĞÊ²Ã´³ÌĞò,¾­³£ÉîÒ¹
´«³öµÃÒâµÄĞ¦Éù,ÏëÀ´ÊÇ¸ö¹¤×÷¿ñÈË°É......
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
