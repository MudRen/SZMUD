//code by cheap
//11/10/01
#include <ansi.h>

inherit ROOM; 

void create()

{
        set("short",HIC"大门"NOR);
        set("long",
"这里是车行的大门，一块“车行”的大匾高挂在门梁上。两扇朱木大门打开\n"
"著。在大门口的两旁放著两头张开口含著石珠的石狮子。这里的人还蛮多了，他\n" 
"们都是来这里租矿车，上山挖矿的。\n " 
); 
        set("outdoors",
                     "city");
        set("exits", ([ 
                   "enter":"/newjob/tiejiang/dating",
                   "west":"/newjob/tiejiang/gate1",
                               ])); 
        set("objects", ([ "/newjob/tiejiang/npc/xiaosi.c" : 1,   ]) );
        set("no_clean_up",0);
       setup();
}
