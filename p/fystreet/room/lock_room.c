//indoor.c zip@hero 2000.1.27 ·¿×ÓÄÚ²¿
#include <ansi.h>
#define ID 500
inherit ROOM;
void create()
{	set("short","[1;33mÊÀÃ³ÖĞĞÄ´óÏÃ[37;0m");
	set("long",@LONGLONGAGO
ÊÀÃ³ÖĞĞÄ´óÏÃÓÉÄÏ±±Á½×ùË«×ÓÂ¥¹¹³É£¬Â¥¸ß411Ã×£¬110²ã¡£
ÊÇÉñÖİ×î¸ßµÄ½¨Öş¡£µÚ107²ãÊÇ²tÍûÌü£¬¼«Ä¿Ô¶Ì÷£¬ÉñÖİÃÀ¾°¾¡
ÊÕÑÛµ×¡£ ´óÂ¥¼¯ÉÌÎñ¡¢Ã³Ò×¡¢·şÎñµÈĞĞÒµÓÚÒ»Éí£¬ÉñÖİ¸÷½çÃû
Á÷£¬¹¤ÉÌÒµ¡¢½ğÈÚÒµ¡¢ITÒµµÈ¾«Ó¢¾ùÜöİÍÓÚ´Ë¡£ µØÏÂ»¹ÓĞÎå²ã
Îª´óĞÍ³¬ÊĞ¼°Í£³µ³¡¡£ ´óÏÃÇ°µÄ¹ã³¡¾ÍÓĞµØÌúÕ¾³ö¿Ú£¬½»Í¨·½
±ã¡£×ÔÅ¦Ô¼ÊÀÃ³ÖĞĞÄ±»¿Ö²À·İ×Ó´İ»Ùºó£¬Îª·ÀÉñÖİÓĞ±¾.À­µÇµÄ
×·ËæÕß£¬´óÂ¥¼ÓÇ¿ÁË°²¼ì´ëÊ©¡£´óÂ¥ÉÏ¿Õ5¹«Àï·¶Î§ÄÚÉèÎª½û·É
Çø£¬ËÄÖÜÒş±Î´¦¹²ÉèÓĞÁù´¦°®¹úÕßµ¼µ¯·¢Éä¼Ü¡£
LONGLONGAGO	);
	set("exits",([
        "out":"/p/fystreet/street"+(string)ID,
		]));
	set("owner","lock");
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
   call_other("/p/fystreet/board/lock_board","???");
}
#include "indoor_func.c"
