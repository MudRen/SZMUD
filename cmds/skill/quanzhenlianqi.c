// Code of ShenZhou
// exercise.c

#include <skill.h>

inherit F_CLEAN_UP;

string *koujue = ({
	 "《修真活计有何凭，心死群情今不生》",
	 "《精气充盈功行具，灵光照耀满神京》",
	 "《秘语师传悟本初，来时无久去无馀》",
	 "《历年尘垢揩磨尽，偏体灵明耀太虚》"
});

int exercising(object me);
//int halt_exercise(object me, object who, string why);
int halt_exercise(object me);

int main(object me, string arg)
{
        int exercise_cost;
        object where;

        seteuid(getuid());
        where = environment(me);

        if (!wizardp(me) && me->query("test-qzlq") != "ok")
                return notify_fail("此功能测试中，你不能使用。\n");

        if (where->query("pigging"))
                return notify_fail("你还是专心拱猪吧！\n");

        if (where->query("sleep_room"))
		return notify_fail("在睡房里不能打坐，这会影响他人。\n");

        if (where->query("no_fight"))
		return notify_fail("这里空气不好，不能打坐。\n");

        if (where->query("name") == "大车里")
		return notify_fail("车里太颠簸, 打坐会走火入魔. \n");

        if (me->is_busy() || me->query_temp("pending/exercising") || me->query_temp("exit_blocked"))
                return notify_fail("你现在正忙着呢。\n");

        if( me->is_fighting() )
                return notify_fail("战斗中不能练内功，会走火入魔。\n");
        
        if (me->query_temp("cursed", 1))
                return notify_fail("什么？\n");

        if( me->query("rided"))
                return notify_fail("在坐骑上打坐，会走火入魔。\n");

        if( !stringp(me->query_skill_mapped("force")) )
                return notify_fail("你必须先用 enable 选择你要用的内功心法。\n");

        if( !arg || !sscanf(arg, "%d", exercise_cost))
                return notify_fail("你要花多少气练功？\n");
        if (exercise_cost < 10)
                return notify_fail("你的内功还没有达到那个境界！\n");

        if( (int)me->query("qi") < exercise_cost )
                return notify_fail("你现在的气太少了，无法产生内息运行全身经脉。\n");

        if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 )
                return notify_fail("你现在精不够，无法控制内息的流动！\n");

        if ( (int)me->query("neili") > (int)me->query("max_neili") * 2 )
        {
                me->set( "neili",me->query("max_neili") * 2 );
        }

	if( me->query_skill_mapped("force") == "xiantian-gong"
	 && (int)me->query_skill("xiantian-gong") >= 50
	 && (int)me->query_skill("xuanmen-xinfa") >= 50)
	{
		write("你按着玄门内功心法的气诀坐下来运气用功，一股内息开始在体内流动。\n");
		me->set_temp("quanzhen_lianqi","start");
	}else write("你坐下来运气用功，一股内息开始在体内流动。\n");
        me->set_temp("pending/exercise", 1);
        me->set_temp("exercise_cost", exercise_cost);
        message_vision("$N盘膝坐下，开始修炼内力。\n", me);
        me->start_busy((: exercising :), (:halt_exercise:));
        return 1;
}

int exercising(object me)
{
	int cost;
        int exercise_cost = (int)me->query_temp("exercise_cost");
	int neili_gain = 1 + (int)me->query_skill("force") / 10;
        if (me->query("max_neili") < 3600) neili_gain = neili_gain * 2;
        if (exercise_cost < 1)
                return 0;
	if( me->query_temp("quanzhen_lianqi")=="start")
	{
		if( base_name(environment(me)) == "/d/zhongnan/yangxin" )
			cost = cost/3*2;
		neili_gain = 2 + (int)me->query_skill("force") / 5 + (int)me->query_skill("xuanmen-xinfa",1) / 10;
		cost = neili_gain*3/2;
		write("你默念着"+koujue[random(4)]+"，只觉得一股内息在体内迅速流动，全身都感到舒畅无比。\n");
		me->receive_damage("jing", cost/10, "打坐走火入魔死了");
	}else cost = neili_gain;

        me->add("neili", neili_gain);
        me->set_temp("exercise_cost", exercise_cost -= neili_gain);

        //me->add("qi", -neili_gain);
        me->receive_damage("qi", neili_gain, "打坐走火入魔死了");

        if (exercise_cost > 0)
                return 1;
	me->set_temp("quanzhen_lianqi","stop");
        me->set_temp("pending/exercise", 0);
        message_vision("$N运功完毕，深深吸了口气，站了起来。\n", me);
        if ((int)me->query("neili") < (int)me->query("max_neili") * 2)
                return 0;
        else {
                if ((int)me->query("max_neili") > (int)me->query_skill("force") * me->query("con") * 2 / 3) {
                        write("你的内力修为似乎已经达到了瓶颈。\n");
                        me->set("neili", (int)me->query("max_neili"));
                        return 0;
                }
                else {
                        me->add("max_neili", 1);
                        me->set("neili", (int)me->query("max_neili"));
                        write("你的内力增加了！！\n");
                        return 0;
                }
        }
}

int halt_exercise(object me)
{
        if ((int)me->query("neili") > (int)me->query("max_neili") * 2)
                me->set("neili", (int)me->query("max_neili") * 2);
	me->set_temp("quanzhen_lianqi","stop");
        me->set_temp("pending/exercise", 0);
	return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : exercise|dazuo [<耗费「气」的量> 必须多于 10]

运气练功，控制体内的气在各经脉间流动，藉以训练人体肌肉骨骼的耐
力、爆发力，并且用内力的形式将能量储备下来。

HELP
        );
        return 1;
}
