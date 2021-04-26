// outdoor.c zip@hero 2000.1.27 ·¿×ÓÃÅ¿Ú
#include <ansi.h>
#define ID 200
inherit ROOM;
void create()
{	string *dir=({"¶«","Î÷"});
	set("short",HIG"ÉñÖİ´ó½Ö"+chinese_number(ID/100)+"ºÅ"+dir[ID%2]+NOR);
	set("long",@LONG
ÕâÀïÊÇÉñÁÄ(chat)µÄ[1;32m¾ÛÏÍ×¯[37;0m¡£
    ÕâÀïÊÇ´«ËµÖĞµÄÌúÑªÃËÁúÍ·ÀÏ´óÉñÁÄµÄ¾ÓËù¡£
LONG	);
	set("exits",([
	"west" : __DIR__"street"+(string)(ID/100),
	]));
	set("owner","chat");
	set("coor/x",40+(ID%2)*20);
	set("coor/y",20+(ID/100)*10);
	set("coor/z",0);
	setup();
}
#include "outdoor_func.c"