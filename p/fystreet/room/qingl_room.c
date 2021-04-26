//indoor.c zip@hero 2000.1.27 ·¿×ÓÄÚ²¿
#include <ansi.h>
#define ID 701
inherit ROOM;
void create()
{	set("short","[35m¹ÛĞÇĞ¡Öş[37;0m");
	set("long",@LONGLONGAGO
ÕâÊÇÒ»¼äËä²»¿í³¨£¬È´ÊÕÊ°µÃºÜÕû½àµÄ¿ÍÌü¡£
  ÕıÖĞ°Ú·Å×ÅÒ»ÕÅ×ö¹¤¿¼¾¿£¬¹ÅÉ«¹ÅÏãµÄ°ËÏÉ×À£¬
  ËÄÖÜËæÒâµØÂë·Å×Å¼¸ÕÅÖñÒÎ¡£
  ´°±ßÊÇÒ»ÅèÊ¢¿ª×ÅµÄË®ÏÉ£¬
  ´°ÍâÒşÔ¼¿É¼ûÒ»ÌõÍäÍäµÄĞ¡Ïª¾²¾²µØÁ÷ÌÊ¡£
  Î¢·ç´µ¹ı£¬ËÍÀ´ÂÆÂÆ×ÏÖñµÄÇåÏã£¬ÁîÈË¾«ÉñÎªÖ®ÇåË¬ÁËĞí¶à¡£
  ´°µÄÁ½²àÊÇÖ÷ÈË×Ô¼ºÊéĞ´µÄÒ»¸±¶Ô×Ó£º
      Ò» Éú Ğ¯ ÊÖ£¬ÒĞ Â¥ Ìı ·ç Óê
      Ò» ÊÀ Ïà °é£¬µ­ ¿´ ½­ ºş Â·
LONGLONGAGO	);
	set("exits",([
//         "up":"/u/snowyu/yangtai1",
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","qingl");
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
   call_other("/p/fystreet/board/qingl_board","???");
}
#include "indoor_func.c"
