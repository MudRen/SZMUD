//indoor.c zip@hero 2000.1.27 ·¿×ÓÄÚ²¿
#include <ansi.h>
#define ID 1500
inherit ROOM;
void create()
{	set("short","ÏóÑÀ°×Ëş[37;0m");
	set("long",@LONGLONGAGO
¡¡¡¡³¤Äê²»¼ûÌìÈÕ£¬ÇàÌ¦¾ÍËÁÎŞ¼Éµ¬µØµ½´¦Éú³¤£¬¸¯³ôÆøÎ¶Ö±³å±Ç¶Ë£¬Òì³£É­º®µÄÎÂ¶È£¬ÔÚ ;µØÉÏ½á³ÉÒ»²ãÓÖÒ»²ãµÄºñËª£¬²»Ê±ÓÖ×ªÎª°×ÑÌ£¬È½È½ÉÏÃ°£¬¶ñÁÓµÄ»·¾³£¬¾ÍÊÇÒ»¸ö¼«¶ÈÏÕÄÑ ;µÄµØ·½¡£ ;
;¡¡¡¡
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","szlr");
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
   call_other("/p/fystreet/board/szlr_board","???");
}
#include "indoor_func.c"
