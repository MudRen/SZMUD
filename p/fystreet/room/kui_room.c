//indoor.c zip@hero 2000.1.27 ·¿×ÓÄÚ²¿
#include <ansi.h>
#define ID 2200
inherit ROOM;
void create()
{	set("short","[1;37m°×[1;37m[1;33m½ğ[1;33m[1;37mºº¹¬[1;37m[37;0m");
	set("long",@LONGLONGAGO
Ó¢¹ú»Ê¼Ò¹¬µî£®¾Û¼¯×ÅÓ¢¹úÊı°ÙÄêÀ´£¬ÔÚÊÀ½ç¸÷µØÂÓ¶áÀ´µÄ±¦Îï£®
µ±ÖĞ·Å×ÅÖĞ¹úÇå´úµÄÁúÒÎ£®×ó±ßÊÇÒ»¸öÓÃÒâ´óÀûÌìÈ»´óÀíÊ¯ÖÆ×÷³ÉµÄÍÁ¶úÆäÉ£ÄÃÔ¡³Ø£®
ÓÒ±ßÊÇÒ»¸ö°£¼°³ö²úµÄ»Æ½ğÖÆµÄÆÁ·ç£®
ÆÁ·çºóÃæÓĞÒ»¸ö³¬¼¶´óµÄÈí´²£®´²ÊÇºÃÏóÒşÒşÔ¼Ô¼ÓĞ¸öæ¹ÄÈ¶à×ËµÄÉíÓ°£¨¿´µÄÄãÖ±Á÷±ÇÑª£©£®
ÔÚ·¿¼äµÄÖĞÑë·Å×ÅÒ»Ö»³ö×ÔÃåµéµÄºìÄ¾´ó×À×Ó£®
ÉÏÃæ·Å×ÅĞí¶àÀ´×ÔÊÀ½ç¸÷µØµÄÃÀÎ¶¼ÒÒª£¬£´¸öplayboy µÄ·âÃæÅ®ÀÉÔÚÅÔ±ßËæÊ±×¼±¸·şÊÌÄãhappy.....(ÊÇ³Ô·¹À²£¡±ğÂÒÏë£¡£©
Í»È»Äã·¢ÏÖkui ÕıÔÚÁúÒÎÉÏ°ÚÅª×ÅËûµÄÆÆµçÄÔ£®Ò»¸öÈË¶Ô×ÅmudÏ²Ï²ÉµĞ¦£®
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","kui");
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
   call_other("/p/fystreet/board/kui_board","???");
}
#include "indoor_func.c"
