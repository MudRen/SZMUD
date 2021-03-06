// yunu-xinjing 玉女心经
// by April 01/08/06
// update April 01/08/08
// update by chchong 2001/08/12

// COLOR DEFINE
// RED - 红色              HIR - 亮红色
// GRN - 绿色              HIG - 亮绿色
// YEL - 土黄色            HIY - 黄色
// BLU - 深蓝色            HIB - 蓝色
// MAG - 浅紫色            HIM - 粉红色
// CYN - 蓝绿色            HIC - 天青色
// WHT - 浅灰色            HIW - 白色

#include <ansi.h> 
#include <combat.h>

inherit FORCE;
string check() { return "force"; }
#include "/kungfu/skill/force_list.h"

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// cant learn
{
        return notify_fail
			("你尝试了一下，觉得似乎总也不得要领。唉，看来玉女心经是一门需要在实践中提高的内功。\n");
}

int practice_skill(object me)	// 其实以下代码都无法运行到... :)
{
	int xj_lvl;		// 心经lvl
	int v,i,j,k;		// 临时变量
	int cost;		// 练习时的耗费
	mapping skl;	// 所有skill
	string *sname;	// skill名字
	object *inv;	// 身上带的东西


	xj_lvl = me->query_skill("yunu-xinjing", 1);

	// lvl小于30不能练
	if (xj_lvl<30)
		return notify_fail("你试着运了一下体内真气，显然玉女心经修为不够，真气无法运转。\n");

	// 必须空手
	if ( me->query_temp("weapon") )
        return notify_fail("练习玉女心经必须空手，静坐诚心方可。\n");

	// 必须裸体
	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++)
		if( inv[i]->query("equipped") 
			&& inv[i]->query("armor_type")=="cloth")
			i = sizeof(inv)+1;
	if (i==sizeof(inv)+2)
        return notify_fail("练习玉女心经必须衣襟敞开方能及时散发热气。\n");

	// 内功要纯，否则大伤元气
	skl=this_player()->query_skills();
	sname=sort_array( keys(skl), (: strcmp :) );
    for(v=0; v<sizeof(skl); v++) {
		if (SKILL_D(sname[v])->check() == "force")
			k++;  
    }
    if ( k >=2 ) {
		// 这里加走火入魔伤害
        me->set("neili", 0);
        me->set("jingli", 50);
        me->set("qi", 50);
		i=(int)(me->query("max_jing")*0.65);
		me->set("eff_jing",i);
	
		return notify_fail("你体内不同内力互相冲撞，翻江倒海，难以克制。 \n"
			+"你猛一咬牙，狂喷一口热血，才不至于走火入魔。\n");
	}

	// 不能靠练习过关 ---- 30n-1时必须过关
	if ( (xj_lvl<270) && ((xj_lvl+1)/30*30 == xj_lvl ) )
		return notify_fail("你继续练习着玉女心经，忽然体内真气一滞... \n"
			+"你似乎遇到了无法突破瓶颈，看来是时候过关了。 \n");

	// 计算练功消耗
	cost = (int)((sqrt(xj_lvl/150))*60);
	if ( (int)me->query("qi") < cost+10 )
		return notify_fail("你的体力不够练习玉女心经。\n");
	if ( (int)me->query("jingli") < cost+10 )
		return notify_fail("你的精力不够练习玉女心经。\n");
	if ( (int)me->query("neili") < cost+10 )
		return notify_fail("你的内力不够练习玉女心经。\n");

	// 消耗
	me->add("neili", -cost);
	me->receive_damage("jingli", cost, "精力透支过度死了");
	me->receive_damage("qi", cost, "体力透支过度死了");
    
    return 1;
}

string exert_function_file(string func)
{
	return "/kungfu/skill/yunu-xinjing/" + func;
}
mixed hit_by(object me, object victim, int damage, int damage_bonus, int factor)
{
         if (victim->query_temp("ngsuxin"))
         {
                 return 0;
          }
          else return damage;
}

mapping curing_msg(object me)
{
	return ([
		"start_self"    : WHT"你就地盘坐，运使玉女心经疗伤，内息鼓动顿时热气蒸腾，浑身大汗淋淋。\n"NOR,
		"start_other"   : WHT+me->name()+ "就地盘坐，浑身白气，开始运功疗伤。\n"NOR,
		"finish_self"   : "你催动玉女心经疗伤多时，一道真气在体内运转无碍，内伤已经恢复，当即站起身来。\n",
		"finish_other"  : WHT"只见"+ me->name()+ "头顶白气弥漫，脸上由白变红，忽然间一声长啸，站起身来。\n"NOR,
		]);
}


