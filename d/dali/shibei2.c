// Code of ShenZhou
//zyz /12/13/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "ÊÀ×æ»ÊµÛÆ½ÔÆÄÏ±®");
        set("long", @LONG
³ÇÎ÷ÈýÔÂ½ÖÉÏ£¬´£Á¢×ÅÒ»¿é¾Þ±®¡°ÔªÊÀ×æÆ½ÔÆÄÏ±®¡±¡£¾Þ±®
ÃæÁÙ¶ýº££¬±³ÒÐ²ÔÉ½£¬ÎµÎª×³¹Û¡£´Ë±®Á¢ÓÚÔª´óµÂ°ËÄê(Ò»ÈýÁãË
ÄÄê)£¬±®ÎÄ×«Ð´ÕßÊÇ
º²ÁÖ³ÌÎÄº££¬¸èËÌÒÑÈ¥ÊÀµÄÔª³¯¿ª¹ú»ÊµÛÊÀ×æºö±ØÁÒµÄ¡°Ê¥µÂÉñ¹¦¡±¡£ÓÚ
ÊÇÁ¢ÁË´Ë±®£¬¾Þ±®¸ßËÄ¡£ËÄËÄÃ×£¬¿íÒ»¡£ÁùÎåÃ×£¬ÓÃ¶þÊ¯Ïà½Ó¶ø³É¡£±®ÎÄ
¹²ÎåÊ®ÐÐ£¬ÉÏÊ¯ÈýÊ®ÐÐ£¬Ã¿ÐÐ¶þÊ®×Ö£¬ÏÂÊ¯¶þÊ®°ËÐÐ£¬Ã¿ÐÐ¶þÊ®Îå×Ö¡£È«
±®Ò»Ç§Èý°Ù×Ö×óÓÒ£¬ÕýÊé£¬±®¶î×­Êé¡°ÊÀ×æ»ÊµÛÆ½ÔÆÄÏ±®¡±°Ë×Ö¡£
LONG
        );

        set("outdoors", "dali");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

