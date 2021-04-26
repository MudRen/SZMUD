// room /d/wulin/shangshan.c
//updated by Lara 2001/10/17
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "英雄大会广场");
        set("long", @LONG
此处就是英雄大会广场了。每当武林中有重大的事情发生，武林盟主便会在
此召开英雄大会，商榷大事，武林中各路高手都会云集于此，景象甚是宏大。在
广场的前面有座高台，台上面摆着一个黄金宝座，上面镶嵌着各种色彩眩目的宝
石。在宝座的后面竖着一根直冲云天的大旗，旗上“替天行道”四个大字在阳光
照射下闪闪发光。
LONG
        ); 
                set("exits", ([
                  "west" : __DIR__"shangwu",
                  ]));
                set("objects",([
                __DIR__"npc/yishi" : 2,
        ]));

                set("cost", 1);
                setup();
         call_other("/clone/board/hero_b", "???");

}



