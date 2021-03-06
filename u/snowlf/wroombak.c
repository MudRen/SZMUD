// workroom.c 沁涟宫 ℅骇甤
// snowlf by 2001.09.17
// snowlf change of 2001.9.30 (add board)  
#include <room.h>
#include <ansi.h>

inherit ROOM;

void reset();
int valid_leave();

void create()
{
        set("short",HIG"沁涟宫"NOR);
        set("long","一座晶莹剔透的水晶宫，整座宫殿包括室内的器物几乎全都是用水晶
做的，屋顶镶嵌一颗硕大的"+HIW+"夜明珠"+NOR+"(yemingzhu)，正对门的方向有一张"+HIW+"八仙
桌"+NOR+"(desk)，旁边有客座(zuo)，桌上放著一盆"+HIR+"珊瑚"+NOR+"盆景，整个宫殿给人感觉
是无比的清逸脱俗，西边有座跨院(kuayuan)，东边的走廊(zoulang)通往
后花园，轻风徐徐，不时飘来阵阵花香！
");
        set("no_fight", 1);           
        set("valid_startroom",1);
        
        set("exits", ([
         	"west" : __DIR__"kuayuan",
		"out" : __DIR__"asgard-door",
		"east" : __DIR__"zoulang",
		"down" : "/d/xingxiu/lingshan",
        "newjob" : "/u/snowlf/room/meeting_room",
		"hmsz" : "/u/lisser/hmsz-dy",
		
        ]));

        set("item_desc", ([
                        "yemingzhu": "一颗硕大的夜明珠，散发出璀灿的光辉 ，是宫中的照明之物。\n",
                        "kuayuan": "西边的跨院是沁涟宫主的寝宫和婢女们住处，男宾请止步！\n",
                        "desk": "八仙桌是水晶做的，桌上放著一盆珊瑚盆景和一卷缣素(jian su).\n",
                        ]));     
        set("valid_startroom",1);
        set("no_clean_up",0);
        set("no_fight",1);
        set("no_steal",1);
        set("objects",([ 
                __DIR__"gongnu1":1,                
                __DIR__"gongnu2":1,   
                "/d/taohua/obj/xiangcha" : 1,
                "/clone/wiz/guo": 2,              
       
]));
        setup();
        call_other("/clone/board/jiansu", "???");
}
