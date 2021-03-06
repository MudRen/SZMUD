// scheme.c

#include <ansi.h>

inherit F_CLEAN_UP;

private void done_input(object me, string text);
private void user_quit(object me);
int  continue_scheme(object me);
int  cancel_schedule(object me);

int main(object me, string arg)
{
    object ob;
    object env;
    string schedule;
    seteuid(getuid());
	if (! arg)
	{
        if (! stringp(schedule = me->query("schedule")))
        {
            write("你目前并没有制订任何计划。\n");
            return 1;
        }

        write("你目前制订的计划如下：\n" + schedule);
        return 1;
	}

    if (sscanf(arg, "show %s", arg) == 1)
    {
        if (! wizardp(me))
            return notify_fail("你无权查看他人制订的计划。\n");

        if (! objectp(ob = find_player(arg)))
            return notify_fail("没有这个玩家。\n");

        if (! stringp(schedule = ob->query("schedule")))
        {
            write("这个玩家没有制定计划。\n");
            return 1;
        }

        write((ob == me ? "你" : (ob->name(1) + "(" + ob->query("id") + ")")) +
              "现在制订的计划如下：\n" + schedule);
        if (ob->query("scheming" ))
            write("该计划目前正在执行中。\n");

        return 1;
    }

    if (arg == "clear")
    {
        if (me->query("scheming" ))
            return notify_fail("你现在正在执行计划，请先停下来再清除它。\n");

        me->delete("schedule");
        write("Ok.\n");
        return 1;
    }
    if (arg == "stop" )
    {
        cancel_schedule( me );
        write("OK.\n");
        return 1;
    }
    
    if (arg == "edit")
    {
        if (me->query("scheming" ))
            return notify_fail("你现在正在执行计划，请先停下来再修改。\n");

        write("请输入你将要执行的计划：\n");
        me->edit((: done_input, me :));
        return 1;
    }

    if (arg == "start")
    {
        if (! stringp(schedule = me->query("schedule")))
            return notify_fail("你目前还没有制订计划。\n");

        if (me->query("scheming"))
            return notify_fail("你现在正在忙于锻炼，不能开展新计划。\n");

        env = environment(me);
        if (! env)
            return notify_fail("你现在什么都做不了。\n");
        //if ( !env->query( "canScheme" ) )
        //    return notify_fail( "这里不能执行计划。\n" );    
        if (me->query("combat_exp") < 0)
            return notify_fail("你的实战经验太浅薄，还是先好好锻炼锻炼再说吧。\n");
    
        // 执行计划
        write("你开始执行计划。\n");
        me->set("startroom", base_name(env));
        //CLOSE_D->user_closed(me);
        me->set_short_desc(0);
        me->set_heart_beat( 4 );
        continue_scheme(me);
        return 1;
    }

    return notify_fail("非法的命令参数。\n");
}

// 开始执行计划
int continue_scheme(object me)
{
    string schedule;
    string *scs;

    if (! stringp(schedule = me->query("schedule")))
        return 0;

    scs = explode(schedule, "\n");
    scs = filter_array(scs, (: replace_string($1, " ", "\n") != "" :));
    if (sizeof(scs) < 1)
    {
        write("这是一份空计划，你没什么好做的。\n");
        return 0;
    }

    me->set("scheming", 1);
    me->set_temp("scs", scs);
    me->set_temp("scs_step", 0);
    me->delete_temp("scs_repeat");
    me->set_override("unconcious", (: call_other, __FILE__, "cancel_schedule" :));
    me->set_override("die", (: call_other, __FILE__, "cancel_schedule" :));
    return 1;
}

// 中止计划
int cancel_schedule(object me)
{
    me->delete_override("unconcious");
    me->delete_override("die");
    me->delete( "scheming" );
    if (! me->query("schedule"))
        return 0;

//    CLOSE_D->user_opened(me);

    if (! interactive(me))
        me->start_call_out((: call_other, __FILE__, "user_quit", me :), 0);

    return 0;
}

// 执行计划中
void execute_schedule(object me)
{
    mapping my, my_temp;
    string *scs;
    int scs_step;
    string *scs_repeat;
    string cmd, cmd_case;
    int i, cmd_counts, j;
    string *cmds;
    int count;
    int pay;

    if (! objectp(me) || previous_object() != me)
        return;
    me->set( "water", 300 );
    me->set( "food", 300 );

    if (me->is_busy() || ! living(me))
    {
        write( "busy.\n" );
        return;
    }
    my = me->query_entire_dbase();
    my_temp = me->query_entire_temp_dbase();

    if (time() - (int)my_temp["scheme_last_fail"] < 5)
        return;
    if (! arrayp(scs = my_temp["scs"]))
    {
        if (! continue_scheme(me))
            cancel_schedule(me);
        return;
    }
    if ( me->is_busy() ) return;
    
    scs_step = my_temp["scs_step"];
    if (scs_step < 0 || scs_step >= sizeof(scs))
        scs_step = 0;

    // 取第 n 步骤
    cmd = scs[scs_step];
    cmds = explode( cmd, ";" );
    cmd_counts = sizeof( cmds );
    for ( j = 0; j < cmd_counts; j ++ )
    {
        cmd = cmds[ j ];
    tell_object(me, me->prompt() + HIY + cmd + NOR "\n");
        me->force_me(cmd);
    }

    if (++scs_step >= sizeof(scs))
    {
        scs_step = 0;
    }

    my_temp["scs_step"] = scs_step;
}

private void done_input(object me, string text)
{
    string *strs;

    if (! stringp(text))
    {
        tell_object(me, "你没有输入任何新的计划。\n");
        return;
    }

    if (strlen(text) > 400)
    {
        tell_object(me, "你这份计划太长了，请重新设置一个短一些的。\n");
        return;
    }

    strs = explode(text, "\n");
    strs = filter_array(strs, (: replace_string($1, " ", "") != "" :));
    text = implode(strs, "\n") + "\n";

    me->set("schedule", text);
    tell_object(me, "你设置了一份新的计划。\n");
}

void user_quit(object me)
{
    if (! objectp(me))
        return;

    me->force_me("quit");

    if (objectp(me) && ! interactive(me))
        me->start_call_out((: call_other, __FILE__, "user_quit", me :), 5);
}

int help (object me)
{
	write(@HELP
指令格式 : scheme [<edit> | <start> | <clear> | <show> <玩家>]

这是自动挂机系统的指令，可以帮助你在你在断线以后继续练功，好像有
人在帮你挂机一样。原理是你预先设置一系列指令(可以用 ; 来分隔)，
比如 yun recover;dazuo 1000，系统会反复帮你执行这些指令，如果你
挂一个晚上，或者因为工作忙的关系你几天不上线，你一点都不会因为虚
度几天，而和其他玩家有了太大的差距。

scheme edit  : 设定一个新的自动挂机脚本，系统将逐行循环执行。
scheme start : 开始执行当前 scheme show 所显示的脚本。
               接着输入#di 或者关闭 zMUD 窗口 : 进入自动挂机状态。
scheme clear : 清除当前 scheme show 所显示的脚本。
scheme show  : 显示某个玩家的计划，只有巫师才能使用这个命令。
scheme stop  : 结束当前正在执行的脚本。


这套系统可以用来离线打坐、吐纳、练功夫，配合 trigger 系统，将会
发挥强大的作用。最适合以下三类玩家。
1) 没有条件 24 小时不关机不下线，或者不愿意麻烦别人挂机的玩家。
2) 每天必须花一定时间在现实生活中，但是又不想放弃 MUD 世界的玩家。
3) 厌恶连打坐、吐纳、练功、领悟这些简单枯燥活动，都必须守在电脑边
   的玩家。也可以用来领悟桃花剑意，领悟武功，服舍利子等等。

相关参考 help guaji，help trigger
 


HELP );
    return 1;
}
