// Code of ShenZhou
#include <ansi.h>
inherit ROOM;
 
void create()
{
        set("short", "大湖");
        set("long",@LONG
你坐在小舟穿行于大湖的湖道之中。四边都是藕菱相间的绿叶，湖道
弯弯曲曲,无法分辨它到底通向何处。

LONG);   
        setup();
        replace_program(ROOM) ;
}
