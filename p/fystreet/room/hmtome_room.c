//indoor.c zip@hero 2000.1.27 ·¿×ÓÄÚ²¿
#include <ansi.h>
#define ID 100
inherit ROOM;
void create()
{	set("short","åĞÒ£¾Ó[37;0m");
	set("long",@LONGLONGAGO
   ÕâÊÇÒ»×ù¸Õ½¨µÄÒ»¼ä´ó·¿¼ä£¬´óÔ¼¿É×¡¼¸¸öÈË¡£·¿¼äÖĞÓĞ
Ò»ÕÅÌ´Ä¾´ó´²,±ßÉÏÓĞÒ»Ö»µÊ×Ó£¬ºÍÒ»¸öÊé×À£¬ÓÉÓÚÊÇ
Ö÷ÈË×Ô¼º×¡µÄ£¬ËùÒÔÊÕÊ°µÄºÜ¸É¾»

LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","hmtome");
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
	set("objects", ([__DIR__"obj/cabinet" : 1,]),);
	setup();
   call_other("/p/fystreet/board/hmtome_board","???");
}
#include "indoor_func.c"
