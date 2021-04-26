//indoor.c zip@hero 2000.1.27 ·¿×ÓÄÚ²¿
#include <ansi.h>
#define ID 1201
inherit ROOM;
void create()
{	set("short","ÒÂÒÂĞ¡Öş[37;0m");
	set("long",@LONGLONGAGO
Ğ¡ÖşÖĞÖÖÂúÁË°×É«µÄ¶¡Ïã»¨£¬Î¢·ç´µ¹ı£¬·ºÆğÕóÕó»¨ÀË£¬»¨ÏãÆË±Ç¡£
Ò»×ù¸§ÇÙÌ¨´¦ÓÚ»¨º£ÖĞ£¬ÎªÁËÕÚÑô£¬Ö÷ÈËÇÉË¼ÔÚÇÙÌ¨ÉÏ³ÅÆğÁË°×É´
Ã¿µ±·çÆğÇÙÏìÉ´Æ®Ê±£¬ÓÌÈç´¦ÓÚÊÀÍâÏÉ¾³
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","eida");
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
   call_other("/p/fystreet/board/eida_board","???");
}
#include "indoor_func.c"
