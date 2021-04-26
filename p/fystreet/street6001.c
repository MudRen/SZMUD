// outdoor.c zip@hero 2000.1.27 ·¿×ÓÃÅ¿Ú
#include <ansi.h>
#define ID 6001
inherit ROOM;
void create()
{	string *dir=({"¶«","Î÷"});
	set("short",HIG"ÉñÖİ´ó½Ö"+chinese_number(ID/100)+"ºÅ"+dir[ID%2]+NOR);
	set("long",@LONG
ÕâÀïÊÇË®ÁµÔÂ(daydream)µÄ[1;37m Ô²ÃÎ¾Ó[37;0m¡£
    Ò»¸öÔ²ÃÎµÄµØ·½.¿ªĞÄµÄ»ò²»¿ªĞÄµÄ¶¼ÊÕ²ØÔÚÕâĞ¡Ğ¡µÄÎİ×ÓÀï.
LONG	);
	set("exits",([
	"east" : __DIR__"street"+(string)(ID/100),
	]));
	set("owner","daydream");
	set("coor/x",40+(ID%2)*20);
	set("coor/y",20+(ID/100)*10);
	set("coor/z",0);
	setup();
}
#include "outdoor_func.c"