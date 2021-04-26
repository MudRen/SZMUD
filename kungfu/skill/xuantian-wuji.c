// xuantian-wuji 玄天无极功

#include <ansi.h>
inherit FORCE;
string check() {return "force";}
#include "/kungfu/skill/force_list.h"


int valid_enable(string usage)
{
	return usage == "force";
}


int valid_learn(object me)
{
int lvl = (int)me->query_skill("xuantian-wuji", 1);
int t = 1, j; 
mapping skl;
string *sname;
int i,k=0;
skl=this_player()->query_skills();
sname=sort_array(keys(skl), (: strcmp :) );
if(me->query_skill("xuantian-wuji", 1) > 99){
for(i=0; i<sizeof(skl); i++) {
if (SKILL_D(sname[i])->check() == "force")
k++;
}

if ( k >=2 ) 
return notify_fail("你体内不同内力互相冲撞，难以领会更高深的内功。\n"); 
}

    if ( (int)me->query_skill("force",1) < 10 )
   return notify_fail("你的基本内功火候还不够。\n");

    if (lvl > 10 && (int)me->query("shen") < t * 100)
   return notify_fail("你的侠义正气太低了。\n");

    return 1;
}

int practice_skill(object me)
{
        if ( me->query_skill("xuantian-wuji", 1) < 180 )
                return notify_fail("你的玄天无极功修为不够，只能用学(learn)的来增加熟练度。\n");
        if ( me->query_temp("weapon") )
                return notify_fail("练习玄天无极功必须空手挥掌运气方可。\n");
        if ( (int)me->query("qi") < 70 )
                return notify_fail("你的体力不够练习玄天无极功。\n");
        if ( (int)me->query("jingli") < 70 )
                return notify_fail("你的精力不够练习玄天无极功。\n");
        if ( (int)me->query("neili") < 70 )
                return notify_fail("你的内力不够练习玄天无极功。\n");

	if ( me->query_skill("xuantian-wuji", 1) < 250 ) {
        	me->add("neili", -80);
        	me->receive_damage("jingli", 80, "精力透支过度死了");
        	me->receive_damage("qi", 80, "体力透支过度死了");
	}
	else {
		me->add("neili", -100);
                me->receive_damage("jingli", 100, "精力透支过度死了");
                me->receive_damage("qi", 100, "体力透支过度死了");
	}

        return 1;
}

string exert_function_file(string func)
{
	return __DIR__"xuantian-wuji/" + func;
}
mapping curing_msg(object me)
{
return ([
"start_other" :HIY+me->name()+"盘坐在地上，运起了玄天无极功疗伤。 \n"NOR,
"start_self" :HIY"你盘坐起，运行玄天无极功，打通了全身大穴，调气疗伤。 \n"NOR,
"unfinish_other":HIY"过了一会，"+me->name()+"感到全身通泰了很多，但是身上的伤势还没痊瘀。 \n"NOR,
"unfinish_self":HIY"你感到全身通泰了很多，但是身上的伤势还没痊瘀。 \n"NOR,
"finish_other":HIY+me->name()+"站立了起来，感到全身通泰。 \n"NOR,
"finish_self":HIY"你站立了起来，感到全身通泰。 \n"NOR,
]);
}
