#include <ansi.h> 
         
inherit ROOM; 
        
void create() 
       
{ 
set("short", HIC"打铁场"NOR); 
 set("long", @LONG 
这是一座颇具规模的打铁场，东南角上有一个水池，打铁场的四周有许多专 
用的打铁室，不时传来叮叮铛铛的金属撞击声，正北面是临街一家打铁铺的后门 
，西北的方向通往大街的路很宽，可以容两辆大马车并行，也不会显得拥挤。场 
中央停着几辆骡车，好些人正在那儿忙着装卸一此打铁的原料和成品。 
LONG 
); 
       
                      set("no_fight", "1");  
       
              set("exits", ([ 
                    "east" : "/newjob/tiejiang/datiefang1.c", 
                   "west" : "/newjob/tiejiang/datiefang2.c", 
                    "south" : "/newjob/tiejiang/datiefang3.c", 
                    "down" : "/newjob/tiejiang/datiefang4.c", 
                    "north": "/d/city/datiepu", 
                    "northwest" : "/d/city/dongdajie1", 
       
                       ])); 
       
              set("objects", ([ 
                          __DIR__"npc/bai" : 1, 
                              ]) ); //Newbe add 
       
              setup(); 
			          call_other("/clone/board/tiejiang_b", "???");

      } 
      //Newbe add 
    int valid_leave(object me, string dir) 
    {  
            if (dir == "south" && !me->query_temp("datiechang/enter") || dir == "west" && !me->query_temp("datiechang/enter")  
            || dir == "east" && !me->query_temp("datiechang/enter") || dir == "down" && !me->query_temp("datiechang/enter")) 
            return notify_fail("你还没得到主管同意呢。\n"); 
            return 1; 
    } 
       
       
