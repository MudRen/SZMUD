//indoor.c zip@hero 2000.1.27 ·¿×ÓÄÚ²¿
#include <ansi.h>
#define ID 2400
inherit ROOM;
void create()
{	set("short","[1;33m¼¦ñ¼[37;0m");
	set("long",@LONGLONGAGO
ÕâÊÇĞ¡ÀÇµÄ¼¦ñ¼,ÊÇÄĞÈËÑ°ÀÖµÄºÃµØ·½.Ò»½øÃÅ,¾ÍÁîÈË¾«ÉñÒ»Õñ.
¾­¹ı×ßÀÈ,ÀïÃæÊÇºÜ´óµÄ´óÌü.ÀïÃæ¼«Ö®ÊæÊÊ,¶øÇÒÆ¯ÁÁÃÃÃÃ¶¼´¦¶¼
ÊÇ.ÁîÈËÒâÏë²»µ½µÄÊÇ,Ê²Ã´¹ú¼ÒµÄÃÃÃÃ¶¼ÓĞ.ÓĞÖĞ,·¨,ÈÕ,ÃÀ,¶í,
Éí²Ä´Ó32AÖÁ38F,ÒÂ×Å´ÓÑ§Ğ£·ş,µ½±È¼áÄá,ÉõÖÁÃ»´©¶¼ÓĞ.Ğ¡ÀÇµÄ
µÄÅóÓÑµ½ÕâÀïÀ´µÄ,¶¼Éá²»µÃ×ß,ËµÎ´Íæ¹».
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","zenklee");
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
   call_other("/p/fystreet/board/zenklee_board","???");
}
#include "indoor_func.c"
