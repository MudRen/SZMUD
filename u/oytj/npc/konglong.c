inherit NPC;
#include <ansi.h>

object owner, rider;

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

void create()
{
        set_name(HIM "小恐龙" NOR , ({ "kong long", "long"}) );
    set("race", "家畜");
    set("age", 130);
        set("long", "彩虹的专用坐骑。\n");

		set("str", 100);
		set("con", 100);
		set("dex", 100);
		set("int", 10);
		set("qi", 100000);
		set("wildness", 4);
		set("value", 1000);
		set("ability", 400);
		set("max_qi", 100000);
                set("owner","oytj");
		set("combat_exp", 100000);
                set("max_jingli", 100000);

		set_weight(500000);

		setup();
}

void init()
{
        ::init();
        add_action("do_ride", "qilong");
        add_action("do_zoulu", "go");
        add_action("do_paolu", "goto");
        add_action("do_qingren", "qingren");
        add_action("do_xialong", "xialong");
        add_action("do_longeat", "longeat");
}
int do_longeat(string arg)
{
        string target, msg;
        object obj, me;
        me = this_player();
        target = arg;
        obj = find_object(target);
        if (me!=owner) return notify_fail("你没骑在上面呀。\n"); 
//      if (!wizardp(me)) return notify_fail(HIM"暴龙"NOR"不肯听你的话。\n");
        if (!obj) obj = present(target, me);
        if (!obj) obj = present(target, environment(me));
        if (!obj) obj = find_object( resolve_path(me->query("cwd"), target) );
        if (!obj) return notify_fail("没有这样物件....。\n");
        if( environment(me)==environment(obj) )
        message_vision(HIM"小恐龙"NOR HIY"一口把"NOR MAG +obj->query("name")+ NOR HIY"吞了下去。\n"NOR, me, obj);
        destruct(obj);
        write("吃完了。\n");
        return 1;
}
int do_qingren(string arg)
{
        object victim, me = this_player();
        string comm;
                
        if (!arg) return notify_fail("坐那么高别乱看！\n");
//              if (!wizardp(me)) return notify_fail(HIM"小恐龙"NOR"不是你能骑的\n");
                if (owner!=me) return notify_fail(HIM"小恐龙"NOR"不肯听你的命令。\n");
        victim = present(arg, environment(me));
                if (rider) return notify_fail(HIM"小恐龙"NOR"只能搭乘两人，再多它就不肯跑了。\n");
        if (!victim) return notify_fail(HIM"小恐龙"NOR"转了几圈找不到你想请的人。\n");
        if (!living(victim)) return notify_fail(HIM"小恐龙"NOR"转了几圈发现你想请的人昏了。\n");

        message_vision(YEL "$N拍了拍"NOR HIM"小恐龙"NOR YEL"的头，只见"NOR HIM"小恐龙"NOR YEL"慢慢伏在地上，让$N带着$n安全的骑上了它的头上。\n"NOR, me, victim);

        rider = victim;
        victim->set_leader(me); 
        victim->set_temp("apply/short", ({MAG+victim->name()+"威风凛凛的陪着"+me->name()+"骑在"NOR HIM"小恐龙"NOR MAG"头上"+NOR+"("+victim->query("id")+")"}));
        victim->set_temp("apply/long", ({victim->name()+"威风凛凛的陪着"+me->name()+"骑在"HIM"小恐龙"NOR"头上\n"}));

                return 1;
}
int do_zoulu(string arg)
{
                object env, obj, ob, me = this_player();
                string target_dir, dir, dest, victim;
                mapping exit;
                string riderstr;

                env = environment(me);
                if (me!=owner) return notify_fail(HIM"小恐龙"NOR"不肯听你的命令。\n");
                if (!arg) return notify_fail(HIM"小恐龙"NOR"在原地转了一圈。\n");
        if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) ) 
                        return notify_fail(HIM"小恐龙"NOR"转了几圈找不到你想去的放向。\n");
                dest = exit[arg];
        if( !(obj = find_object(dest)) )
                call_other(dest, "看不懂。");
        if( !(obj = find_object(dest)) )
                return notify_fail("走不了。\n");
                if( !undefinedp(default_dirs[arg]) )
                target_dir = default_dirs[arg];
        else
                target_dir = arg;
        message_vision(GRN "$N骑着"NOR HIM"小恐龙"NOR GRN"往"NOR MAG +target_dir+ NOR GRN"慢慢的跑了出去。\n" NOR, me);
        
        riderstr = me->name();
        if (rider) {
                riderstr += "和"+rider->query("name");
        }
        if( me->move(obj) ) {
                        message( "vision", GRN +riderstr+"骑着"NOR HIM"小恐龙"NOR GRN"慢慢的跑了过来。\n" NOR, environment(me), ({me}));
                        move(obj);
                        if (rider) {
                                rider->move(obj);
                                }
                        return 1;
                        }

        return 0; 
}

int do_paolu(string arg)
{
        int goto_inventory = 0;
        object obj, victim, me = this_player();
        string msg;
                string riderstr;;

                if (me!=owner) return notify_fail(HIM"小恐龙"NOR"不肯听你的命令。\n");

        if( !arg ) return notify_fail(HIM"小恐龙"NOR"在原地转了一圈。\n");

        if( sscanf(arg, "-i %s", arg) ) goto_inventory = 1;

        if( !arg ) return notify_fail(HIM"小恐龙"NOR"在原地转了一圈。\n");

        obj = find_player(arg);
        if(!obj) obj = find_living(arg);
        if(!obj || !me->visible(obj)) {
                arg = resolve_path(me->query("cwd"), arg);
                if( !sscanf(arg, "%*s.c") ) arg += ".c";
                if( !(obj = find_object(arg)) ) {
                        if( file_size(arg)>=0 )
                                return me->move(arg);
                        return notify_fail(HIM"小恐龙"NOR"找不着你想找的人。\n");
                }
        }
                if(!goto_inventory && environment(obj))
                obj = environment(obj);

        if( !obj ) return notify_fail(HIM"小恐龙"NOR"去不了你想去的地方。\n");

        if( !me->query("env/invisibility") ) {
                message_vision(MAG"$N骑着"NOR HIM"小恐龙"NOR MAG"一下子冲了出去。\n" NOR, me);
        }

        if( me->move(obj) ) {
                                riderstr = me->name();
                if (rider) {
                                riderstr += "和"+rider->query("name");
                                message( "vision", MAG +riderstr+"骑着"NOR HIM"小恐龙"NOR MAG"冲了进来。\n" NOR, environment(me), ({me}));
                                tell_object(rider,HIM"小恐龙"NOR YEL"突然跑了起来，你吓的紧紧抱住"NOR MAG+owner->query("name")+ NOR YEL"！\n"NOR);
                    move(obj);
                                rider->move(obj);
                }               
                        else
                        message( "vision", MAG +riderstr+"骑着"NOR HIM"小恐龙"NOR MAG"冲了进来。\n" NOR, environment(me), ({me}));
            move(obj);
                }
        return 1;
}

int do_ride(string arg)
{
        object victim, me = this_player();
                
//        if (this_player()->query("id")!="oytj") return notify_fail("你要先问彩虹给不给你骑。\n");
//              if (!wizardp(me)) return notify_fail(HIM"小恐龙"NOR"不是你能骑的！\n");
                if (me->query("env/invisibility")>0) return notify_fail("对不起你隐身，"HIM"小恐龙"NOR"不让你骑！\n");

        victim = this_object();
                if (owner) return notify_fail("你还没下来呢。");
                message_vision(CYN "$N对着"NOR HIM"小恐龙"NOR CYN"挥了挥手，只见"NOR HIM"小恐龙"NOR CYN"慢慢伏在地上，让$N轻易的骑上了它的头上。\n", me);
        owner = me;
                victim->set_leader(me);
                victim->set("env/invisibility",10);
                me->set_temp("apply/short", ({MAG+me->name()+"骑在"NOR HIM"小恐龙"NOR MAG"的头上"+NOR+"("+me->query("id")+")"}));
                me->set_temp("apply/long", ({me->name()+"威风凛凛的骑在"NOR HIM"小恐龙"NOR"头上\n"}));
        return 1;
}
int do_xialong(string arg)
{
        object victim, me = this_player();
        
//        if (this_player()->query("id")!="oytj") return notify_fail("你要先问彩虹给不给你骑。\n");
//              if (!wizardp(me)) return notify_fail(HIM"小恐龙"NOR"不是你能骑的。\n");
                if (!arg) {
                        if (me!=owner)  
                                return notify_fail("你没骑在上面呀。\n"); 
                victim = this_object();
                message_vision(HIY "$N纵身一溜，从"NOR HIM"小恐龙"NOR HIY"背部滑了下来。\n"NOR, me);
                owner = 0;
                victim->set_leader(me);
                victim->set("env/invisibility",0);
                me->delete_temp("apply/short");
                me->delete_temp("apply/long");
                return 1;       
                }

                
        victim = present(arg, environment(me));

        if (rider ==0) return notify_fail("没有人呀。\n");
        if (!living(victim)) return notify_fail("他昏了拉。\n");

        message_vision(HIY "$N轻轻一推，让$n从"NOR HIM"小恐龙"NOR HIY"背部滑了下来。\n"NOR, me, victim);

                rider = 0;
        victim->delete_leader(); 
        victim->delete_temp("apply/short");
        victim->delete_temp("apply/long");
        
        return 1;
}
