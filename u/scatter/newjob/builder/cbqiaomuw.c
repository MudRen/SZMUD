//room: /newjob/builder/cbqiaomuw.c 长白西乔木林
//Lara 2001/11/11
//这里伐木时随机会出现野狼或熊攻击玩家
//乔木林里有一、二、三等三类建筑木材，主要是二等木材
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "乔木林");
        set("long", 
"这里长满了"+HIW"白桦"NOR+"、"+HIR"红松"NOR+"等大树，由于树木长得相当茂密，气候也逐渐
暖和起来，树下零星长着几朵漂亮的小花，有"+MAG"紫色"NOR+"的，也有"HIM+"粉色"NOR+"的。据说
有人在这里碰到过熊，到了冬天经常有猎人结伴了来捕熊，平时独个儿他
们是不敢到来这里的。\n"
        );

        set("exits", ([        
        "east" : __DIR__"cbailin",
        "south" : __DIR__"cbailinw",
        "north" : __DIR__"cbjumuw",
        ]));
        set("no_clean_up", 0);           
        set("cost", 1);
        setup();
}
