// Room: /d/wuguan/chufang2.c
// 洗盘子任务之厨房

#include <ansi.h>
inherit ROOM;

void create ()
{
        set ("short", "厨房");
        set ("long", @LONG
这儿是泉州武馆的厨房，干净整齐，墙边的柜子里放着整整齐齐的
餐具。厨房的一角有一个小小的水池，里面是清清的水，你可以在这儿
洗（xi）些什么。
LONG);
        set("no_dazuo",1);
        set("no_kill",1);
        set("no_fight",1);
        set("out_door","pingan");
        set("can_wash",1);
        
        set("exits", ([ /* sizeof() == 1 */
               "east" : __DIR__"chufang",
        ]));
        setup();
}

void init()
{
        add_action("do_xi","xi");
}

int do_xi(string arg)
{
        object me, ob; 
        me=this_player();
        
        if ( !arg || arg != "panzi" )
                return notify_fail("你要洗什么？\n");
        
        if ( !me->query_temp("gongzuo/xipanzi") )
                return notify_fail("你还是先去给老妈子打个招呼吧。\n");
        if ( !(ob = present("zang panzi", this_player() )) )
                return notify_fail("你没有脏盘子，怎么能洗呢？\n");
        if ( (int)me->query("jing")<20)
                return notify_fail("你太累了，歇息下吧。\n");
        if ( me->query_temp("gongzuo/xipanzi") >= 6 )
                return notify_fail("盘子洗好了！送回老妈子那儿吧。\n");
   
        message_vision("$N从池子里勺起水，开始慢慢的洗盘子。\n",me);
        me->add("jing",-(10 + random(10)) );
        me->add_temp("gongzuo/xipanzi", random(3) );
        if ( (int)me->query_temp("gongzuo/xipanzi") >=6 ) {
                
                message_vision(CYN"$N洗了良久，终于将盘子全部洗好了。\n"NOR, me);
                tell_object(me,"你累的直不起腰来了，先休息一下吧！\n");
                me->start_busy(3);
                
                ob->set_name( "盘子" , ({"pan zi"}));
                ob->set("long","一叠刚洗好的盘子。\n");
        }
        return 1;
} 
