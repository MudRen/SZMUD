// 侠客行100海洋版II
// panzi.c 洗好的盘子
// 星星lywin 2000/6/1 儿童节
// recode by sinan@sz 2002_3_29
// 脏盘子洗完后变成盘子，在洗盘子的房间set("can_wash",1)

#include <ansi.h>
inherit ITEM;


void create()
{
        set_name( "脏盘子" , ({"zang panzi"}));
        set_weight(3);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "叠");
                set("long", "一叠刚刚用过的脏盘子。\n");
                set("value",0);
        }
        
        setup();
}

/*
void init()
{
        add_action("do_xi","xi");
}


int do_xi(string arg)
{
        object me, ob; 
        me=this_player();
        
        if ( !me->query_temp("gongzuo/xipanzi") )
                return notify_fail("你还是先去给店小二打个招呼吧。\n");
        if ( !arg || arg != "panzi" )
                return notify_fail("你要洗什么？\n");
                
        if ( !environment(me) || !environment(me)->query("can_wash"))
                return notify_fail("你只能在厨房里洗盘子。\n");
                
        if ( !(ob = present("zang panzi", this_player() )) )
                return notify_fail("你没有脏盘子，怎么能洗呢？。\n");
        if ( (int)me->query("jing")<20)
                return notify_fail("你太累了，歇息下吧。\n");
        if ( me->query_temp("gongzuo/xipanzi") >= 6 )
                return notify_fail("盘子洗好了！送回店小二那儿吧。\n");
   
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
*/
