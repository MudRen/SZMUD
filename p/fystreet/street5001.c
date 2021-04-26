// outdoor.c zip@hero 2000.1.27 ·¿×ÓÃÅ¿Ú
#include <ansi.h>
#define ID 5001
inherit ROOM;
void create()
{	string *dir=({"¶«","Î÷"});
	set("short",HIG"ÉñÖİ´ó½Ö"+chinese_number(ID/100)+"ºÅ"+dir[ID%2]+NOR);
	set("long",@LONG
ÕâÀïÊÇ¿áÏÀ(kuxia)µÄ[1;36m¿áÏÀ [1;37m& [1;32mĞ¡°×²Ë [1;33mµÄ[1;35mÎÂÇé[1;34mÎÏ¾Ó[37;0m¡£
    ÕâÊÇ¿áÏÀÎªĞ¡°×²Ë¸ÇµÄÎÂÇéÎÏ¾Ó£¬´Ó´ËĞ¡°×²Ë²»ÔÙÁ÷ÀË£¬ÓĞ¿ÕËûÃÇ¾Í»áÔÚÕâÀïÎÂÇéÒ»»á¶ù¡£^_^
LONG	);
	set("exits",([
	"east" : __DIR__"street"+(string)(ID/100),
	]));
	set("owner","kuxia");
	set("coor/x",40+(ID%2)*20);
	set("coor/y",20+(ID/100)*10);
	set("coor/z",0);
	setup();
}
#include "outdoor_func.c"