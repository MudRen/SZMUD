//¹ã³¡ by remove 15/09/2001
#include <ansi.h>
inherit ROOM;
void create()
{
     set("short", "µ±ÆÌºóÌÃ");
     set("long", @LONG
ÕâÀïÊÇµ±ÆÌµÄºóÌÃ£¬Îİ×ÓÀïÃ»ÓĞ¿ª´°»§£¬Ö»ÓĞ×ÀÉÏµã×ÅÒ»ÕµĞ¡Ğ¡µÄÓÍµÆ¡£¬
ºÚ°µÖĞÄãÒşÔ¼¿´¼û×ÀºóÒõÓ°Àï×ø×ÅÒ»¸öÈË¡£
LONG);
     set("exits", ([
        "out" : __DIR__"dangpu",]));
     set("objects", ([
            __DIR__"npc/xixiashizhe" : 1]));
    set("no_clean_up", 1); 
    setup();
}


