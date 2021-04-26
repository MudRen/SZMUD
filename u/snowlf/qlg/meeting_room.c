 // meeting_room.c 会议室 会某デ
// snowlf by 2001.10.23
#include <room.h>
#include <ansi.h>

inherit ROOM;

void reset();
int valid_leave();

void create()
{
        set("short",HIG"多职业系统第一组的临时工作室"NOR);
        set("long","观荷亭的二楼目前已改做多职业系统第一组的临时工作室，屋顶镶嵌
着一颗"+HIW+"夜明珠"+NOR+"(yemingzhu)，作为夜间照明之用，中间的小会客桌(desk)
上有招待客人的茶果和一个精致的小记事本(cahier)。里间(enter)是分冥
子设计的秘密工作室。  
    
    "+HIM+"轻风徐徐，不时从亭外的荷池飘来阵阵清香！

"NOR);
        
        set("exits", ([
        

                
                "snowlf" : __DIR__"asgard_door", 
                "scatter" : "/u/scatter/workroom",
                "hopeful" : "/u/hopeful/workroom",
                "cheap" : "/u/cheap/workroom",
                "charm" : "/u/charm/workroom",
                "sys" : "/d/wizard/sys_r",
                "enter" : "/newjob/tiejiang/meeting",  
                "tj" : "/newjob/tiejiang/tjtmp_room",
                "down" : __DIR__"qingxinting", 
                "up"  : __DIR__"yangtai", 
                        
        ]));

        set("item_desc", ([
                        "yemingzhu": "一颗硕大的夜明珠，散发出璀灿的光辉 ，是沁涟宫的照明之物。\n",

                        "desk": "一张打磨得很精致的大理石桌，桌上有招待客人的茶果和一个精致的小记事本。.\n",
                        ]));     
        set("valid_startroom",1);
        set("no_clean_up",1);
        set("no_fight",1);
        set("no_steal",1);
        set("objects",([
                __DIR__"npc/gongnu1":1,
                __DIR__"npc/gongnu2":1,
                "/d/taohua/obj/xiangcha" : 1,
                "/d/xingxiu/obj/hamigua": 1,
                "/d/wudang/obj/mitao": 1,

]));

        setup();
        call_other("/clone/board/cahier", "???");
}

