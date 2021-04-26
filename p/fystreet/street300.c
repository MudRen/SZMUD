// outdoor.c zip@hero 2000.1.27 ·¿×ÓÃÅ¿Ú
#include <ansi.h>
#define ID 300
inherit ROOM;
void create()
{	string *dir=({"¶«","Î÷"});
	set("short",HIG"ÉñÖİ´ó½Ö"+chinese_number(ID/100)+"ºÅ"+dir[ID%2]+NOR);
	set("long",@LONG
ÕâÀïÊÇ½ğÔª±¦±¦(yuanbao)µÄ[1;37mÒÆ[1;35m»¨[1;36m¹¬[37;0m¡£
ÕâÀï±ßÊÇÎÅÃûÌìÏÂµÄÒÆ»¨¹¬, ½ğÔª±¦ÉèÔÚ³¤°²µÄĞĞ¹¬.
LONG	);
	set("exits",([
	"west" : __DIR__"street"+(string)(ID/100),
	]));
	set("owner","yuanbao");
	set("coor/x",40+(ID%2)*20);
	set("coor/y",20+(ID/100)*10);
	set("coor/z",0);
	setup();
}
#include "outdoor_func.c"
