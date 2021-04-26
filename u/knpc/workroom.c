#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIB"天山龙门客栈"NOR);
        set("long", @LONG
此处乃西疆边陲，西北是闻名江湖之星宿圣地，北面是小镇伊犁,
此去西南是西方丝绸之路之必经之路,故此来往商旅也颇为众多，百
许年来，更为盗贼匪寇所垂青，只不过最近10年间，据闻一星宿门人
占地开店，生意却火红离奇，更有甚者朝廷，西夏，大理人氏神秘出
入......
LONG
        );

//      set("no_fight", 1);
        set("exits",([
                 "fun": "/u/knpc/dilao.c",
                 "gm": "/d/gumu/fengfang.c",
                 "xx" : "/d/xingxiu/xiaoyao.c",
                 "yz" : "/d/city/kedian.c",
                 "thd" : "/d/taohua/hyjuchu.c",
                 "xixia" : "/d/xixia/center.c",
        ]));

              set("objects", ([ 
                   "/u/knpc/npc/zhanggui.c" : 1, 
                   "/u/knpc/npc/dashou.c":2,
                ]));
        set("cost", 0);
        setup();
    
       call_other("/clone/board/knpc_b", "???")
;
}

int valid_leave(object me, string dir)
{
        object *inv;
        int i;
        inv = all_inventory(me);
        if ( dir == "out" ) {
                for (i=0; i<sizeof(inv); i++) {
                        if (inv[i]->is_character())
                        return notify_fail("你干什么啊？想拐带儿童啊！！\n");
                }
        }

        return ::valid_leave(me, dir);
}
