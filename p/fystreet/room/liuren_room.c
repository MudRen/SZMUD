//indoor.c zip@hero 2000.1.27 ·¿×ÓÄÚ²¿
#include <ansi.h>
#define ID 1101
inherit ROOM;
void create()
{	set("short","°Ë½ä¾Ó[37;0m");
	set("long",@LONGLONGAGO
ÔÚÕıÃæµÄÇ½ÉÏÊÇÒ»ÎªÃÀÅ®,³àÂãÂãµÄ.ºÍÉĞÃÀÅ®Ò²·çÁ÷.
ËıÒşÒİµÄ³¯×ÅÄãÎ¢Ğ¦¸ö²»Í£.Ë¿Ë¿µÄĞã·¢ÈÃÄã ÏëÍüµôËùÓĞ¿Õ.Ö´ÄÛµÄĞ¡ÊÖÕı³¯×ÅÄãÕÅ¿ñ.
ÈÌ²»×¡¿ÚË®¶¼Á÷Ëü¸öÂúµØÂä»¨.
×Ô¹Å·çÁ÷ÈË¾¡°®.
ºÍÉĞÃÀÅ®Ò²³É°¦
²»ÊÇÃøòÈ½Ğ·ï»Ë.
ÄÑµÃ´ºÏôÖµÇ§½ğ
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","liuren");
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
   call_other("/p/fystreet/board/liuren_board","???");
}
#include "indoor_func.c"
