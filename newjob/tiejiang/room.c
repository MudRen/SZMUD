//code by cheap
//11/10/01/
#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short",HIC"杂货店"NOR);
        set("long",
"这里是城里刚刚新开张的杂货铺，一块“买卖公平”的大匾高挂在约五尺高\n" 
"的柜台上方，旁边的一些江湖人士正低声的和老板娘商量着买卖价格，老板娘微\n" 
"笑的打量着你，在店的东边立著一块牌子(paizi)。\n " 
           ); 

        set("exits", ([ 
            "east":"/newjob/tiejiang/gate1",
                      ])); 

       set("item_desc", ([ 
            "paizi" : "本店出售以下用品:
     镐(Gao)             ：二两白银
     钢钎(Qian)          ：二两白银
     大铁锤(Da tie chui) ：一两白银\n" ,
                         ]));
        set("objects", ([ 
            "/newjob/tiejiang/npc/tian.c" : 1,   ]) );
        set("day_shop",1);
        set("no_clean_up",0);
        setup();
}

