// workroom.c 风铃飘香居 
//by aya 4 2002 
#include <ansi.h>; 
inherit ROOM; 

void create()  
{
        set("short", "风铃飘香居"); 
        set("long", @LONG
  这是巫师阿娅的住所，房间典雅别致，一进房子你就能感觉  
  到阵阵花香，窗台上放着一盆灵儿最喜欢的水仙花(hua)，窗户
  的上方挂着一风铃(windbell),一阵风吹来，风铃发出“叮当” 
  的美妙声音。由于她爱游览天下，所以她挖了许多地道在这儿，
  可以到你想去的地方。  
LONG
        );

        set("exits", ([ 
                "out":"/d/wizard/wizard_room",
                "gm":"/d/gumu/houtang", 
                "sl":"/d/shaolin/guangchang1", 
        ])); 

        set("item_desc", ([  
                "hua" : "一盆含苞欲放的水仙，发出淡淡清香\n",  
                "windbell" : "一个叮叮当当的风铃，非常漂亮。\n", 
        ]));  

        set("objects", ([  
                __DIR__"npc/ya" : 1,   
                __DIR__"obj/ziqing.c" : 1,   
        ])); 

        set("sleep_room",1); 
        set("no_fight",1);
        set("no_steal",1);
        setup();
}
