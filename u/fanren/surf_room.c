#include <ansi.h>
inherit ROOM;
void create()
{
               set("short", "神医屋");
        set("long", @LONG
这里由一棵大树改造成的屋子，座落在神医平一指那药铺的出进之处,一望下去
就是扬州城里的闹市了。街坊们都说这里的神医似乎是武当派里的人物不知怎么了会
在此处替人治病，听说对于疗伤和疗毒有一定的造诣。一名小厮站在柜台后招呼着
顾客。柜台上贴着一张发黄的牌子(paizi)。
LONG);
        set("exits", ([
                      "down" : "/d/city/yaopu",
  ]));
              set("objects",([
  "/d/dali/npc/xiaosi" : 1,
   ]));
set("item_desc", ([ 
                "paizi" : "疗伤驱毒，童叟无欺。\n",
  ])); 
setup();
}
