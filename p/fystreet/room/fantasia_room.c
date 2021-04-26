//indoor.c zip@hero 2000.1.27 ·¿×ÓÄÚ²¿
#include <ansi.h>
#define ID 801
inherit ROOM;
void create()
{	set("short","[1;36mÁ÷ĞÇ»¨Ô°£¨MeteorGarden)[37;0m");
	set("long",@LONGLONGAGO
ÎÂÈáµÄĞÇ¿Õ¡¡Ó¦¸ÃÈÃÄã¸Ğ¶¯¡¡ÎÒÔÙÄãÉíÅÔ¡¡ÎªÄã²¼ÖÃÒ»Æ¬Ìì¿Õ 
²»×¼ÄãÄÑ¹ı¡¡ÌæÄã°ÚÆ½¼ÅÄ¯¡¡ÃÎÏëµÄÖØÁ¿¡¡È«²¿¶¼½»¸øÎÒ
Ç£ÄãÊÖ¡¡¸ú×ÅÎÒ×ß¡¡·çÔÙ´óÓÖÔõÑù¡¡ÄãÓĞÁËÎÒ¡¡ÔÙÒ²²»»áÃÔÂ··½Ïò 
ÉË¸ĞÈôÌ«¶à¡¡ĞÄ¶ª¸øÎÒ±£»¤¡¡Æ£¾ëµÄÑÌ»ğ¡¡ÎÒ¶¼»áÌæÄã¸Ï×ß
²ÓÀÃµÄÑÔÓï¡¡Ö»ÄÜµã×ºÇé¸Ğ¡¡Èç¹ûÎÒ³ÁÄ¬¡¡ÒòÎªÎÒÕæµÄ°®Äã 
Ç£ÄãÊÖ¡¡¸ú×ÅÎÒ×ß¡¡·çÔÙ´óÓÖÔõÑù¡¡ÄãÓĞÁËÎÒ¡¡ÔÙÒ²²»»áÃÔÂ··½Ïò
ÓêºÍÔÆ½¥½¥É¢¿ª¡¡È÷ÏÂÒ»Æ¬ÎÂÅ¯¡¡ÎÒÒª·ÖÏíÄãÑÛÖĞµÄÀá¹â 
ÅãÄãÈ¥¿´ Á÷ĞÇÓê ÂäÔÚÕâµØÇòÉÏ¡¡ÈÃÄãµÄÀáÂäÔÚÎÒ¼ç°ò
ÒªÄãÏàĞÅÎÒµÄ°®Ö»¿ÏÎªÄãÓÂ¸Ò¡¡Äã»á¿´¼ûĞÒ¸£µÄËùÔÚ
P.S. This House is For the Specialest Woman in My Heart
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","fantasia");
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
	set("objects", ([__DIR__"obj/cabinet" : 1,]),);
	setup();
   call_other("/p/fystreet/board/fantasia_board","???");
}
#include "indoor_func.c"
