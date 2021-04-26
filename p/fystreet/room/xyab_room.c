//indoor.c zip@hero 2000.1.27 ·¿×ÓÄÚ²¿
#include <ansi.h>
#define ID 2601
inherit ROOM;
void create()
{	set("short","$GRE$¶´·¿$[37;0m");
	set("long",@LONGLONGAGO
ÊÀ½ç±­µÄÕû¸öÔË×÷¹ı³Ì£¬³ä³â×ÅµäĞÍµÄĞÛĞÔ·ûºÅ£ºÁ÷º¹µÄÄĞÈË¡¢Ç¿×³µÄÉíÌå¡¢´ÖÂ³µÄ¾ÙÖ¹¡¢³©Í¨ÎŞ×èµÄ´Ö¿Ú¡¢É·ÓĞ½éÊÂµÄ¡°²¨¾­¡±(×ãÇòÆÀÊö)¡¢Æ¡¾Æ¡¢»¨Éú¡­¡­¶øËùÓĞµÄ´ÆĞÔ´ú±í£¬¶¼²»¹ı±»Å²ÓÃÀ´×÷Åã³ÄkkĞÔ¸ĞµÄÆ¡¾ÆÅ®ÀÉ¡¢¹ü×Å°ÍÎ÷ÇòÒÂÉí²Ä·áÂúµÄ½ğ·¢Ñóæ¤¡¢¹ı³¡µÄ¿ÍÏ¯Å®Ö÷³ÖÈËkkÒÔÍ¹ÏÔÕâ³¡¼ÎÄê»ª»áµÄÄĞĞÔÖ÷µ¼µØÎ»£¬Ò»ÇĞ°Ú²¼°²ÅÅ£¬¶¼ÊÇ´ÓÄĞĞÔÊÓÏß¹Ûµã³ö·¢¡£;¡¡¡¡¼¸ºõ£¬Ò»¸öÄĞĞÔ±»¹éÄÉÎª×ãÇò°®ºÃÕßÊÇ
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","xyab");
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
   call_other("/p/fystreet/board/xyab_board","???");
}
#include "indoor_func.c"
