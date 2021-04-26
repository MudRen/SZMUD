//indoor.c zip@hero 2000.1.27 ·¿×ÓÄÚ²¿
#include <ansi.h>
#define ID 3901
inherit ROOM;
void create()
{	set("short","¾ÛÔµĞù[37;0m");
	set("long",@LONGLONGAGO

Í¥ÔºÁ½ÅÔ´äÖñ¼ĞµÀ,ÍÁµØÏÂ²ÔÌ¦²¼Âú,ÖĞ¼äÑò³¦Ò»ÌõÊ¯×ÓÂşµÄğ®Â·.¸ÕÖÁ·¿ÖĞ,±ãÓĞÒ»¹ÉÏ¸Ï¸ÌğÏã,Ïò±ÚÉÏ¿´Ê±,ÊÇÌÆÒúµÄ"º£ÌÄ´ºË¯Í¼",Á½±ßÊÇËÎÑ§Ê¿ÇØÌ«ĞéĞ´µÄÒ»¸±¶ÔÁªÔÆ:ÄÛº®ËøÃÎÒò´ºÀä,·¼ÆøÏ®ÈËÊÇ¾ÆÏã.
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","fxcl");
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
   call_other("/p/fystreet/board/fxcl_board","???");
}
#include "indoor_func.c"
