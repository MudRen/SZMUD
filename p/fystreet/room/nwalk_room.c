//indoor.c zip@hero 2000.1.27 ·¿×ÓÄÚ²¿
#include <ansi.h>
#define ID 3600
inherit ROOM;
void create()
{	set("short","[1;32m¾²ÑşÕ«[37;0m");
	set("long",@LONGLONGAGO
Äã¸ÕÒ»½øÃÅ£¬¾Í±»ÕâËù·¿×ÓµÄÆøÅÉÕò×¡ÁË£¡ÕâËù·¿×Ó×Ü¹²·ÖÇ°Ô°ºóÔ°ºÍ
ÖĞÍ¥Èı¸ö²¿·Ö£¬Ç°Ô°ÇàÊ¯°åµØÉÏÒÔ±»²È³öÁËĞí¶àµ­µ­µÄ×ãÓ¡£¬×ã¼û´ËÎİÖ÷ÈË
Îä¹¦Éîºñ£¬ºóÔ°¼ÙÉ½Ë®³Ø£¬Ò»Æ¬´ºÒâ°»È»£¬Äã²»½ûÆæ¹Ö£¬µ½µ×ºÎ·½ÑÅÊ¿ÓĞ´Ë
ÏĞÇéÑÅÖÂ¡£¸Õ½øÖĞÍ¥£¬×ß³öÒ»Î»ôæôæÉÙÅ®£¬Äã¶¨¾¦Ò»¿´£¬¹Ô¹ÔÁúµØ¶«£¬´ËÅ®
Ã²ÈôÌìÏÉ£¬ÕæÄË±ÕÔÂĞß»¨£¬³ÁÓãÂäÑã£¬Ü½ÈØÑıÑŞ£¬Ã÷ÃÄ»Ø´º£¡Äã²»½û½ÅÏÂÒ»
Èí,ÔÎÁË¹ıÈ¥¡£
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","nwalk");
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
   call_other("/p/fystreet/board/nwalk_board","???");
}
#include "indoor_func.c"
