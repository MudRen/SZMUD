// study.c   沁涟宫/书斋
// snowlf by 2001.12.19

#include <room.h>
#include <ansi.h>

inherit ROOM;

void reset();
int valid_leave();

void create()
{
        set("short",HIW"书斋"NOR);
        set("long","
    书斋门楹上题着一副对联：   
    
	     		灯火夜深书有味  
	     		墨花神湛字生光
    
    推门而入，但见正对门的方向有一张"+HIW+"书桌"+NOR+"(desk)，旁边靠墙两个大书
架上放满了书，桌上放著一盆"+HIR+"珊瑚"+NOR+"盆景，屋顶镶嵌一颗硕大的"+HIW+"夜明珠"+NOR+"(yemingzhu)。

"NOR);

        set("valid_startroom",1);
        
        set("exits", ([
		
		"west" : __DIR__"jiuqu5",
		"out" : __DIR__"huayuan",		
        ]));

        set("item_desc", ([
			"yemingzhu": "一颗硕大的夜明珠，散发出璀灿的光辉 ，是宫中的照明之物。\n",
                        "desk": "这是一张汉白玉的书桌，桌上放著一盆珊瑚盆景和一卷缣素(jian su).\n",
                        ]));     
        set("valid_startroom",1);
        set("no_clean_up",0);
        set("no_fight",0);
        set("no_steal",0);
        setup();
        
        call_other("/clone/board/jiansu2", "???");
}
