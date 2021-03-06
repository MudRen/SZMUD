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
        set("long","这是一座晶莹剔透的水晶宫，整座宫殿包括室内的器物几乎全都是用水晶做
的，屋顶镶嵌一颗硕大的"+HIW+"夜明珠"+NOR+"(yemingzhu)，正对门的方向有一张"+HIW+"八仙桌"+NOR+"(desk)
，旁边有客座(zuo)，桌上放著一盆"+HIR+"珊瑚"+NOR+"盆景，整个宫殿给人感觉是无比的清逸脱
俗，西边有座跨院(kuayuan)，东边的走廊(zoulang)通往后花园。

    "+HIM+"轻风徐徐，不时飘来阵阵清香！
    
"NOR);

        set("valid_startroom",1);
        
        set("exits", ([
         	"west" : __DIR__"qlg/kuayuan",
		"out" : __DIR__"qlg/asgard_door",
		"east" : __DIR__"qlg/jiuqu1",

		
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
       
]));
        setup();
        call_other("/clone/board/jiansu", "???");
}
