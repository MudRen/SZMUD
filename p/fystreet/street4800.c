// outdoor.c zip@hero 2000.1.27 ·¿×ÓÃÅ¿Ú
#include <ansi.h>
#define ID 4800
inherit ROOM;
void create()
{	string *dir=({"¶«","Î÷"});
	set("short",HIG"ÉñÖİ´ó½Ö"+chinese_number(ID/100)+"ºÅ"+dir[ID%2]+NOR);
	set("long",@LONG
ÕâÀïÊÇÎÚÃÉ·ò(finger)µÄÌÙÔ­¶¹¸¯µê[37;0m¡£
    ÕâÀïÊÇÇïÃûÉ½½ÅµÄÒ»¼äÆÕÍ¨¶¹¸¯µê£¬ÃÅÃæºÜĞ¡£¬ÃÅ¿ÚÄÇÍ£ÁËÒ»Á¿ÒıÓĞ¡°ÌÙÔ­¶¹¸¯µê(×Ô¼ÒÓÃ)¡±×ÖÑùµÄ
LONG	);
	set("exits",([
	"west" : __DIR__"street"+(string)(ID/100),
	]));
	set("owner","finger");
	set("coor/x",40+(ID%2)*20);
	set("coor/y",20+(ID/100)*10);
	set("coor/z",0);
	setup();
}
#include "outdoor_func.c"