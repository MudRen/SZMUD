// huayuan.c   沁涟宫/沁心亭
// snowlf by 2001.12.19

#include <room.h>
#include <ansi.h>

inherit ROOM;

void reset();
int valid_leave();

void create()
{
        set("short",HIG"沁心亭"NOR);
        set("long","
    在花园的一角，临水有一座精巧别致的亭子，亭基比回廊高出两阶，
亭有三层，中层现已改做多职业系统第一组的临时工作室，西北边一瀑清
流从瑶池泻下，就是这荷池的水源。这亭子以及亭外的曲桥画廊和水榭，
都是赏荷的好去处，凭栏相看，荷塘佳色尽收眼底。

    "+HIM+"徐徐轻风拂面，空气中的清香让人心旷神怡！
"NOR);

        set("valid_startroom",1);
        
        set("exits", ([
		"out" : __DIR__"huayuan",  
		"south" : __DIR__"jiuqu4",
		"east" : __DIR__"jiuqu3",
		"westup" : __DIR__"yaochi",
		"up" : __DIR__"meeting_room",		
        ]));

        set("item_desc", ([
                        "lotus flower": "接天莲叶无穷碧，映日荷花别样红！\n",
			"荷塘佳色": "接天莲叶无穷碧，映日荷花别样红！\n",
                        ]));     
        set("valid_startroom",1);
        set("no_clean_up",0);
        set("no_fight",0);
        set("no_steal",0);
        setup();

}
