// chemahang.c 神州车马行   
// snowlf by 2001.11.14
//troy by 2001.12.13
 
#include <room.h>
#include <ansi.h>

inherit ROOM;

void reset();
int valid_leave();

void create()
{
        set("short",HIW+"神州车马总行"NOR);
        set("long", HIW+"
                      【神州车马行】"+NOR+"简介
                         
    神州车马行在扬州、大理等各大城市都开了分号。车马行的幕
后老板据说是夕年一位风云江湖的武林前辈，后来退隐江湖，把所
有马厩都买了下来，开了车马行，经营各类车辆的租，售业务，方
便往来的商旅。
");

        
        set("exits", ([

                "south" : "/d/city/kedian",
                "enter":"/d/city/majiu",
                "southeast" : "/d/city/beidajie1",
        ]));

       set("out_door","city");
       set("valid_startroom",1);
        set("no_clean_up",1);
        set("no_fight",1);
        set("no_steal",1);
        set("no_get",1);

        set("objects",([
               __DIR__"npc/cmh_huoji":1,
               
    	   ]));     
        setup();

}
