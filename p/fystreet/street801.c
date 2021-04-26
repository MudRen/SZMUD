// outdoor.c zip@hero 2000.1.27 ·¿×ÓÃÅ¿Ú
#include <ansi.h>
#define ID 801
inherit ROOM;
void create()
{	string *dir=({"¶«","Î÷"});
	set("short",HIG"ÉñÖİ´ó½Ö"+chinese_number(ID/100)+"ºÅ"+dir[ID%2]+NOR);
	set("long",@LONG
ÕâÀïÊÇÌìÏÉ×Ó(tianxz)µÄ[1;32mÈµ[1;36mÇÅ[37;0m¡£
    ÕâÊÇ Å£ÀÉ Óë Ö¯Å® Ô¼»á µÄµØ·½£¬Ã¿ÔÂ7ÔÂ7ÈÕ£¬±ØÄÜÔÚ´ÎÏà¼û£»Æ½³£¾Í³ÉÁË ÌìÏÉÒ»×å ÒéÊÂµØµØ·½¡£
LONG	);
	set("exits",([
	"east" : __DIR__"street"+(string)(ID/100),
	]));
	set("owner","tianxz");
	set("coor/x",40+(ID%2)*20);
	set("coor/y",20+(ID/100)*10);
	set("coor/z",0);
	setup();
}
#include "outdoor_func.c"