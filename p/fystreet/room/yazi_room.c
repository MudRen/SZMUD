//indoor.c zip@hero 2000.1.27 ·¿×ÓÄÚ²¿
#include <ansi.h>
#define ID 1000
inherit ROOM;
void create()
{	set("short","[1;37m¾ÛÀÇÕ¬[37;0m");
	set("long",@LONGLONGAGO
ÕâÀïËäÈ»¾Û¼¯ÁËÒ»Èº¶öÀÇ£¬µ«ÊÇËûÃÇµÄĞÄµØ×ÅÊµ²»»µ£¡
Ã¿µ±ÉñÖİµÄMMÃÇÓöµ½Ê²Ã´À§ÄÑ£¬ËûÃÇ¶¼»áÒå²»Èİ´ÇµÄÍ¦Éí¶ø³ö£¡
ÔÚMMµÄ×ìÀï£¬ËûÃÇÓĞ×ÅºÜºÃµÄ¿Ú±®£¡ºÜÊÜMMÃÇµÄÏ²»¶£¡
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","yazi");
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
   call_other("/p/fystreet/board/yazi_board","???");
}
#include "indoor_func.c"
