//indoor.c zip@hero 2000.1.27 ·¿×ÓÄÚ²¿
#include <ansi.h>
#define ID 2100
inherit ROOM;
void create()
{	set("short","[1;36mÌ¤[1;33mÔÂ[1;35mÉ¨[1;37mÑ©[36m¾Ó[37;0m");
	set("long",@LONGLONGAGO
×ó±ßµÄÇ½ÉÏ¹Ò×ÅÒ»°ÑÖñµÑ×Ó£¬µ«ÊÇ·âÂúÁË³¾£¬ÒÑ¾­ºÜ¾ÃÃ»ÓĞÓÃ¹ıÁË¡£Í¸¹ı´°×Ó£¬¿ÉÒÔ¿´µ½Åû×ÅÎíÆøµÄĞ¡ºş£»ºş±ß³¤×ÅºÃÒ»Ğ©ÜÔÀò»¨£¬»¨ÏãÆ®½øÎİ×Ó£¬Ê¹µÃÈËĞÄ¿õÉñâù¡£Îİ¶¥²»ÖªµÀÊÇÓÃÊ²Ã´×öµÄ£¬¿ÉÒÔ¿´µ½Ìì¿Õ¡£ÔÂ¹âÍ¸¹ıÎİ¶¥È÷½øÀ´£¬Ê¹ÈË·Â·ğÖÃÉíÓÚ¿õÒ°Ö®ÖĞ¡£
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","readpost");
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
   call_other("/p/fystreet/board/readpost_board","???");
}
#include "indoor_func.c"
