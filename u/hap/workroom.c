#include <ansi.h>
inherit ROOM;
void create()
{
          set("short", "开心小屋");
        set("long", @LONG
这里是开心儿的小巢。屋子里看起来乱乱的，但是无论你走到那个位置，
都会感觉非常舒适，显然是经过主人精心的布置。墙上挂着副对联：

            宠辱不惊，闲看亭前花开花落；

            去留无意，漫听天外云卷云舒。

LONG);
        set("exits", ([
                  "west" : "/d/city/wumiao",
]));
              set("no_fight", 1); 
              set("valid_startroom",1); 
               call_other("/clone/board/hap_b", "???");  
                 setup(); 
}
