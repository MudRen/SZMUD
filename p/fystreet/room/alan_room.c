//indoor.c zip@hero 2000.1.27 ·¿×ÓÄÚ²¿
#include <ansi.h>
#define ID 3701
inherit ROOM;
void create()
{	set("short","[1;32m·çÖĞµÄ»¨[37;0m");
	set("long",@LONGLONGAGO
ÎÒÏ²»¶Õ¾ÔÚ·ç´óµÄµØ·½
ÈÃ·çÉ³ÕÚÈ¥ÎÒµÄÊÓÏß
Èç´Ë¾Í¿´²»¼û
Ã»ÓĞÃÎµÄÌì¿Õ
ÎÒµÄĞÄÊÇÒ»Æ¬Æ¬µÄ»¨°ê
Ö»ÏëÊØÔÚÄãÀë¿ªµÄµØ·½
ÄãµÄ³ĞÅµ
ÊÇÎ¨Ò»Ö¸ÒıÎÒµÄ·½Ïò
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","alan");
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
   call_other("/p/fystreet/board/alan_board","???");
}
#include "indoor_func.c"
