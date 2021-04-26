//indoor.c zip@hero 2000.1.27 ·¿×ÓÄÚ²¿
#include <ansi.h>
#define ID 300
inherit ROOM;
void create()
{	set("short","[1;37mÒÆ[1;35m»¨[1;36m¹¬[37;0m");
	set("long",@LONGLONGAGO
   ÔÚÕâÀï£¬»¨¿ªµÃÕıÊ¢¡¢¾Õ»¨¡¢Äµµ¤¡¢Ç¾Ş±¡¢Ã·¡¢ÌÒ¡¢À¼¡¢ÂüÍÓÂŞ¡¢Ò¹À´Ïã¡¢Óô½ğÏã¡­
ÕâĞ©±¾²»¸ÃÔÚÍ¬Ò»¸öµØ·½¿ª·Å¸ü²»¸ÃÔÚÍ¬Ò»¸öÊ±ºò¿ª·ÅµÄ»¨£¬´Ë¿ÌÈ´È«¶¼ÔÚÕâÀï¿ª·ÅÁË¡£
×óÊÖ±ßÓĞÒ»¸ö¾Ş´óµÄÓñ×ÁÊé¹ñ, ÀïÃæ·Å×ÅµÄ¾ÍÊÇÎäÁÖÖĞÈËÃÎÃÂÒÔÇóµÄÒÆ»¨¹¬²»Íâ´«Ö®ÃØ!
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","yuanbao");
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
   call_other("/p/fystreet/board/yuanbao_board","???");
}
#include "indoor_func.c"
