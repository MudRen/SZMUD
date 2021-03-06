// Code of ShenZhou
// Keny's skill
// 圣心决

inherit FORCE;
string check() { return "force"; }

#include <ansi.h>
#include "/kungfu/skill/force_list.h"

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
	        mapping skl; 
        string *sname;
        int v, k=0;
        skl=this_player()->query_skills();
        sname=sort_array( keys(skl), (: strcmp :) );

        if(me->query_skill("shengxin-jue", 1) > 99){

       for(v=0; v<sizeof(skl); v++) {
                if (SKILL_D(sname[v])->check() == "force")
                k++;  
        }

        if ( k >=2 )
        return notify_fail("你体内不同内力互相冲撞，难以领会更高深的内功。\n");
        }

	if ( (int)me->query_skill("force", 1)  <  10 
           ||(int)me->query_skill("force", 1)/2 < (int)me->query_skill("shengxin-jue", 1)/3 )
                return notify_fail("你的基本内功火候还不够，无法领会圣心决 。\n");

        if ( me->query("gender") == "无性" && (int)me->query_skill("shengxin-jue",1) > 49)
                return notify_fail("公公无根无性，圣心决再难更上一层楼。\n");


        if ( (int)me->query_skill("shengxin-jue", 1) >= 45 
	&& (int)me->query_skill("huagong-dafa", 1) >= 100
	&& (int)me->query_int() < 40 )
                return notify_fail("你受高深的邪派内功牵绊，与圣心决水火难容，再难更上一层楼。\n");

	return 1;
}

int practice_skill(object me)
{
        if ( me->query_skill("shengxin-jue", 1) < 150 )
                return notify_fail("你的圣心决修为不够，只能用学(learn)的来增加熟练度。\n");
	if ( me->query_temp("weapon") )
                return notify_fail("练习圣心决必须空手，静坐诚心方可。\n");
	if ( (int)me->query("qi") < 70 )
                return notify_fail("你的体力不够练习圣心决。\n");
	if ( (int)me->query("jingli") < 70 )
                return notify_fail("你的精力不够练习圣心决。\n");
	if ( (int)me->query("neili") < 70 )
                return notify_fail("你的内力不够练习圣心决。\n");

	me->add("neili", -60);
	me->receive_damage("jingli", 60, "精力透支过度死了");
	me->receive_damage("qi", 60, "体力透支过度死了");
        return 1;
}

string exert_function_file(string func)
{
        return __DIR__"shengxin-jue/" + func;
}

mapping curing_msg(object me)
{
	return ([
"start_other" :WHT+me->name()+"盘坐在地上，散发著一股雾白色的仙气。 \n"NOR,
"start_self" :WHT"你盘坐起，散发著一股雾白色的仙气，打通了全身大穴，调气疗伤。 \n"NOR,
"unfinish_other": WHT"过了一会，"+me->name()+"收起了那股仙气。 \n"NOR,
"unfinish_self": WHT"你感到全身通泰了很多，收起了那股仙气。 \n"NOR,
"finish_other": WHT+me->name()+"站立了起来，收起了那股仙气。 \n"NOR,
"finish_self": WHT"你站立了起来，收起了那股仙气。 \n"NOR,
	]);
}
