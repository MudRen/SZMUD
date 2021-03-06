//code by cheap
//小推车
#include <ansi.h>
#include <room.h>
inherit ITEM;
mapping default_dirs = ([
        "north":        "北",
        "south":        "南",
         "east":         "东",
        "west":         "西",
        "northup":      "北边",
        "southup":      "南边",
        "eastup":       "东边",
        "westup":       "西边",
        "northdown":    "北边",
        "southdown":    "南边",
        "eastdown":     "东边",
        "westdown":     "西边",
         "northeast":    "东北",
         "northwest":    "西北",
         "southeast":    "东南",
         "southwest":    "西南",
         "up":           "上",
         "down":         "下",
         "out":          "外",
          "enter":        "里",
]);
int do_drive(string arg);
void set_owner(object owner);
void create()
{
        set_name("小推车", ({ "xiao tuiche","che" }));
        set_color("$HIW$");
        set_weight(50000000);
       set_max_encumbrance(700000000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "辆");
                set("long", "这是一辆用来装矿石用的车。\n");
set("value",1000000);
set("no_get",1);
set("checkcar","/newjob/tiejiang/obj/xiao_tc.c");
                   }
}
int is_container() { return 1; }

int reject(object ob)
{
int value;
        if (ob && ob->query("ore") ) return 0;
        notify_fail("你只能放矿物入车里。\n");
        return 1;
}
void init()
{
object ob;
add_action("do_drive","cun");
add_action("do_drive","push");
}
void set_owner(object owner)
{
object ob = this_object();
set("owner", ob);
}

int do_drive(string arg)
{
        object env, obj, ob, me = this_player(), partner;
        string target_dir, dir, dest, victim;
        mapping exit;
        object here = environment(me),robber = present("robber",here);
        int busy_time;

        if (!arg) return notify_fail("你要推什么？\n");

        if( sscanf(arg, "%s %s", victim, dir) != 2 ) return notify_fail("指令错误！\n");

        if ( victim == me->query("id") ) return notify_fail("何必多此一举？\n");

        if ( victim != "che" && victim != "da che" ) return notify_fail("你要推什么？\n");

        ob = present(victim, environment(me));

        if (!ob) return notify_fail("这里并无此人！\n");

        if ( me->is_busy() ) return notify_fail("你在忙着呢！\n");

        env = environment(me);
        if( !mapp(exit = env->query("exits")) || undefinedp(exit[dir]) )
                return notify_fail("无此方向可去！\n");

        dest = exit[dir];

        if( !(obj = find_object(dest)) )
                                         call_other(dest, "???");
                  if( !(obj = find_object(dest)) )
                                         return notify_fail("无法走！\n");
        if( !wizardp(ob) && obj->query("short") == "巫师休息室" )
                return notify_fail("无法走！\n");
if( query("owner") != me->query("id"))
               return notify_fail("这不是你的车! \n");
        if( !undefinedp(default_dirs[dir]) )
                                         target_dir = default_dirs[dir];
                  else
                                         target_dir = dir;

        message_vision( HIG"$N"+HIG"用力推$n"+HIG"朝"+target_dir+"走去。\n" NOR, me, ob);
         me->move(obj);
        if( robber && ( robber->query("owner") == me->query("id") || robber->query("owner2") == me->query("id")) )
        {
                message_vision( HIR"$N喝道：想溜？没门！\n"NOR,robber);
                return 1;
        }

/*
        if( ob->query("owner") != me->query("id") && ob->query("owner2") != me->query("id") )
        {
                message_vision( HIW"可是骡子理都不理$N。\n" NOR,me);
                return 1;
        }
*/

        message("vision", HIY "只见"+ob->name()+HIY"轰隆隆沉重的向"+target_dir+"驶过去。\n" NOR, environment(ob), ({ob}));

        if( ob->move(obj) ) {
                        message( "vision", HIY "只见一辆"+ob->name()+HIY"轰隆隆沉重的驶了过来。\n" NOR, environment(ob), ({ob}));

                        busy_time = 4 + random(4);

                        if( ob->query("owner") )
                        {
                                if( (me = present( ob->query("owner"),env )) && me->query_temp("riding") )
                                {
                                        message_vision( HIG"$N推动"+target_dir+"驶过去。\n" NOR,me);
                                        me->move(obj);
                                        message_vision( HIG"$N推动小推车驶过来。\n" NOR,me);
                                        me->start_busy( busy_time );
                                        all_inventory(env)->follow_me(me,dir);
                                }
                                else if ( (me = present( ob->query("owner"),environment(ob) )) )
                                        me->start_busy( busy_time );
                        }

                        if( ob->query("owner2") )
                        {
                                 if( (partner = present( ob->query("owner2"),env )) && partner->query_temp("riding") )
                                 {
                                        message_vision( HIG"$N坐在镖车上向"+target_dir+"驶过去。\n" NOR,partner);
                                        partner->move(obj);
                                        message_vision( HIG"$N坐在镖车上驶过来。\n" NOR,partner);
                                        partner->start_busy( busy_time );
                                        all_inventory(env)->follow_me(partner,dir);
                                 }
                                 else if( (partner = present( ob->query("owner2"),environment(ob) )) )
                                {
                                if (ob->query("owner2") && ob->query("race") == "人类" )
                                {
                                        partner->start_busy( busy_time );
                                        }
                                }
                        }
 }
        return 1;
}
