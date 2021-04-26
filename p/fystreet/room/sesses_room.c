//indoor.c zip@hero 2000.1.27 ·¿×ÓÄÚ²¿
#include <ansi.h>
#define ID 3601
inherit ROOM;
void create()
{	set("short","[1;31m»ğÉñ¹¬[37;0m");
	set("long",@LONGLONGAGO
Ïç´åĞ¡ÎİÊ½µÄĞ±¶¥·¿£¬Ç½ÃæÉÏÓĞÒ»¸ö´ó´óµÄ³µÂÖ£¬ÃÅÇ°µÄÄ¾Àé£¬Ç½ÉÏµÄºÖÉ«Ä¾°å£¬ÔÚºÚÉ«½ÖµÆµÄ¹âÏßÖĞ¹ÅÆÓÓĞÎ¶¡£ÁÒ»ğµÄĞû´«´ÊÊÇ"¸øºÚÒ¹ÁôÒ»µãÏëÏó£¬ÎÒÓĞÒôÀÖºÍÆ¡¾Æ¡£Î÷ÑóÒôÀÖ¿ªµÃĞ¡Ğ¡£¬¸øÄã°²¾²µÄ¿Õ¼ä£»ÁÒ»ğ»¹ÓĞÍ¦ºÃµÄ¼¦Î²¾ÆºÍ¿§·È¡£
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","sesses");
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
   call_other("/p/fystreet/board/sesses_board","???");
}
#include "indoor_func.c"
